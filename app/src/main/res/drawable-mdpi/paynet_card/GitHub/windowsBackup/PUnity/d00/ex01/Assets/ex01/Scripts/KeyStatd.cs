﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class KeyStatd : MonoBehaviour {

	private float speed;

	// Use this for initialization
	void Start () {
		speed = Random.Range (8, 13);
	}

	// Update is called once per frame
	void Update ()
	{
		transform.Translate(Vector3.down * speed * Time.deltaTime);
		if (transform.position.y < -3.9) 
		{
			Destroy (gameObject);
			//Debug.Log ("Object destroyed");
		}
		if (Input.GetKeyDown (KeyCode.D)) 
		{
			int result = (int)((transform.position.y + 3.9) * 10000);
			if (result < 0)
				result *= -1;
			Debug.Log (result);
			Destroy (gameObject);
		}
	}
}
