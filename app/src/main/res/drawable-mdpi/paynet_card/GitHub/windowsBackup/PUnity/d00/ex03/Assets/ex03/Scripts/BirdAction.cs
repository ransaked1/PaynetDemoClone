using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BirdAction : MonoBehaviour {

	public GameObject pipe;
	private int fall = 4;

	// Use this for initialization
	void Start () {
		
	}

	// Update is called once per frame
	void Update () {
		transform.Translate (Vector3.down * fall * Time.deltaTime);
		fall += 1;
		if (fall >= 6)
			fall = 6;
		if (Input.GetKeyDown (KeyCode.Space))
			transform.Translate (Vector3.up * 99 * Time.deltaTime);
		if (transform.position.y < -3.45) {
			pipe.GetComponent<PipeAction> ().StopPipe ();
			Destroy (this);
		}
	}

	public void StopBird()
	{
		Destroy (this);
		pipe.GetComponent<PipeAction> ().StopPipe ();
	}
}
