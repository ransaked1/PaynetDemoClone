using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

public class DataNDropWeapon : MonoBehaviour {

	public GameObject tower;
	public GameObject manager;
	private static GameObject dragedItem;
	public bool isDragging;
	private bool dropped;

	public Text time;
	public Text damage;
	public Text range;
	public Text energy;

	Vector3 startPos;
	RaycastHit2D hitEmpty;
	Vector3 mouseVector;
	Vector3 newVector;
	Vector3 pos;

	// Use this for initialization
	void Start () {
		time.text = tower.GetComponent<towerScript> ().fireRate.ToString ();
		damage.text = tower.GetComponent<towerScript> ().damage.ToString ();
		range.text = tower.GetComponent<towerScript> ().range.ToString ();
		energy.text = tower.GetComponent<towerScript> ().energy.ToString ();
	}

	// Update is called once per frame
	void Update () {
////		hitEmpty = Physics2D.Raycast (Camera.main.ScreenToWorldPoint (Input.mousePosition), Vector3.zero);
//		pos = Input.mousePosition;
//		pos.z = 1;//hitEmpty.collider.gameObject.transform.position.z;
//		pos = Camera.main.ScreenToWorldPoint(pos);

//		if (isDragging)
//			gameObject.transform.position = pos;
		mouseVector = Camera.main.ScreenToWorldPoint (Input.mousePosition);
		newVector = new Vector3 (mouseVector.x, mouseVector.y, -42);
		if (isDragging) {
			hitEmpty = Physics2D.Raycast (Camera.main.ScreenToWorldPoint (Input.mousePosition), Vector3.zero);
			if (hitEmpty && hitEmpty.collider.gameObject.tag == "empty")
				gameObject.transform.position = Input.mousePosition;//hitEmpty.collider.gameObject.transform.position;
		}

		if (manager.GetComponent<gameManager> ().playerEnergy < tower.GetComponent<towerScript> ().energy) {
			isDragging = false;
			gameObject.GetComponent<Image> ().color = new Color32 (255, 81, 81, 255);
		}
		else
			gameObject.GetComponent<Image> ().color = new Color32 (255, 255, 255, 255);
	}

	public void StartDrag() {
		isDragging = true;
		startPos = this.transform.position;
	}

	public void Drop() {
		if (isDragging == true) {
			isDragging = false;
			hitEmpty = Physics2D.Raycast (Camera.main.ScreenToWorldPoint (Input.mousePosition), Vector3.zero);
			if (hitEmpty && hitEmpty.collider.gameObject.tag == "empty") {
				manager.GetComponent<gameManager> ().playerEnergy -= tower.GetComponent<towerScript> ().energy;
				tower.transform.position = new Vector3 (hitEmpty.transform.position.x, hitEmpty.transform.position.y, 0);
				Instantiate (tower);
			}
			gameObject.transform.position = startPos;
		}
	}
}
