using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpawnKeys : MonoBehaviour {

	public GameObject key;

	private float spawnTime;
	private float timer;

	// Update is called once per frame
	void Update () 
	{
		spawnTime = Random.Range (4, 24);
		if (timer >= spawnTime) 
		{
			timer = 0;
			Instantiate (key, transform.position, transform.rotation);
		}
		timer += Time.deltaTime;
	}
}
