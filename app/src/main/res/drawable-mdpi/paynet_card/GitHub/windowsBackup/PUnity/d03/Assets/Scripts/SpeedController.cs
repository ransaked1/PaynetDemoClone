using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SpeedController : MonoBehaviour {

	public GameObject gm;

	public Button myButton;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		Button btn = myButton.GetComponent<Button>();
		btn.onClick.AddListener(TaskOnClick);
	}

	void TaskOnClick(){
		if (gameObject.tag == "pause")
			gm.GetComponent<gameManager> ().pause (true);
		if (gameObject.tag == "speed1")
			gm.GetComponent<gameManager> ().changeSpeed(1);
		if (gameObject.tag == "speed2")
			gm.GetComponent<gameManager> ().changeSpeed(4);
		if (gameObject.tag == "speed4")
			gm.GetComponent<gameManager> ().changeSpeed(10);
	}  
}
