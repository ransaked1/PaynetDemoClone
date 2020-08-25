using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpawnKeyd : MonoBehaviour {

	public GameObject key;

	private float spawnTime;
	private float timer;

	// Update is called once per frame
	void Update () 
	{
		spawnTime = Random.Range (9, 15);
		if (timer >= spawnTime) 
		{
			timer = 0;
			Instantiate (key, transform.position, transform.rotation);
		}
		timer += Time.deltaTime;
	}
}
