using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InstantiateBalloon : MonoBehaviour 
{

	// Use this for initialization
	void Start () 
	{

	}
	
	// Update is called once per frame
	void Update () 
	{
		if (Input.GetKeyDown(KeyCode.Space))
		{
			transform.localScale += new Vector3 (0.18f, 0.18f, 1);
		}
		transform.localScale -= new Vector3 (0.02f, 0.02f, 1);
		if (transform.localScale.x > 8)
		{
			Debug.Log ("Bah!");
			OnApplicationQuit();
		}
		if (transform.localScale.x < 0.3)
		{
			Debug.Log("Balloon life time: " + (int)Time.time + "s");
			transform.localScale = new Vector3 (0, 0, 1);
			Destroy (this);
		}
	}

	void OnApplicationQuit()
	{
		Debug.Log("Balloon life time: " + (int)Time.time + "s");
		Destroy (this);
		Application.Quit ();
	}
}
