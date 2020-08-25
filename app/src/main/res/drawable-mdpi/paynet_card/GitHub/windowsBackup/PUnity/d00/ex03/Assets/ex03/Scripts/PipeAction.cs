using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PipeAction : MonoBehaviour {

	private float start;
	private float end;
	private int speed = 6;
	public GameObject bird;
	private float timer;
	private float incTime;
	private float gameTime = 0;
	private float score = 0;

	// Use this for initialization
	void Start () {
		start = transform.position.x;
		incTime = 4;
	}
	
	// Update is called once per frame
	void Update () {
		if (timer >= incTime) {
			timer = 0;
			speed += 2;
		}
		timer += Time.deltaTime;
		transform.Translate (Vector3.left * speed * Time.deltaTime);
		if (transform.position.x < -11.50f) {
			score += 5;
			transform.position = new Vector3 (start, -0.22f, 0.5f);
		}
		if ((transform.position.x <= -0.4f && transform.position.x >= -2.4f) && bird.GetComponent<BirdAction>().transform.position.y > 1.1f)
			bird.GetComponent<BirdAction> ().StopBird ();
		if ((transform.position.x <= -0.4f && transform.position.x >= -2.4f) && bird.GetComponent<BirdAction>().transform.position.y < -2.05f)
			bird.GetComponent<BirdAction> ().StopBird ();
		gameTime += Time.deltaTime;
	}

	public void StopPipe ()
	{
		Destroy(this);
		Debug.Log ("Score: " + score.ToString () + " Time:");
		Debug.Log (Mathf.RoundToInt(gameTime) + "s");
	}
}
