using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OrcSpawner : MonoBehaviour {

	private float timer = 0;
	public GameObject orcPref;

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		if (timer > 10) {
			Instantiate (orcPref);
			orcPref.transform.position = transform.position;
			orcPref.transform.tag = "orc";
			timer = 0;
		}
		timer += Time.deltaTime;
	}
}
