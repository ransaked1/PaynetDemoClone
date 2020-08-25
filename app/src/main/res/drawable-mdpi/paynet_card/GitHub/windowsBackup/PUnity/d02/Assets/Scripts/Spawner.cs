using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class Spawner : MonoBehaviour {

	public GameObject soldierPref;
	private List<GameObject> activeSoldiers;
	public float timer = 0;

	void Start()
	{
		activeSoldiers = new List<GameObject>();
//		Instantiate (soldierPref);
//		soldierPref.transform.position = transform.position;
//		soldierPref.tag = "soldier";
//		activeSoldiers.Add(soldierPref);
//		soldierPref.transform.Find ("SoldierDown").GetComponent<PlayerMove>().active = false;
//		Debug.Log ("wat?");
		Instantiate (soldierPref);
		soldierPref.transform.position = transform.position;
		soldierPref.transform.tag = "soldier";
	}

	// Update is called once per frame
	void Update () {
		if (timer > 10) {
			Instantiate (soldierPref);
			soldierPref.transform.position = transform.position;
			soldierPref.transform.tag = "soldier";
			timer = 0;
		}
		timer += Time.deltaTime;

		if (Input.GetMouseButtonDown (0)) {
			RaycastHit hit;
			Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);

			if(Physics.Raycast (ray, out hit))
			{
				if(hit.transform.tag == "soldier")
				{
					Debug.Log ("This is a Player");
					foreach (GameObject obj in activeSoldiers) {
						try {
							obj.transform.Find ("SoldierDown").GetComponent<PlayerMove>().active = false;
						}
						catch {
							obj.transform.parent.gameObject.transform.Find ("SoldierDown").GetComponent<PlayerMove> ().active = false;
						}
					}
					activeSoldiers.Clear();
					activeSoldiers.Add(hit.transform.gameObject);
				}
				else {
					Debug.Log ("This isn't a Player");                
				}
			}
		}
		foreach (GameObject obj in activeSoldiers) {
			try {
				obj.transform.Find ("SoldierDown").GetComponent<PlayerMove>().active = true;
			}
			catch {
				obj.transform.parent.gameObject.transform.Find ("SoldierDown").GetComponent<PlayerMove> ().active = true;
			}
				
		}
	}
}
