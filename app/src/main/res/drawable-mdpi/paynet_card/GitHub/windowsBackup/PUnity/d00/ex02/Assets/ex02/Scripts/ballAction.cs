using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ballAction : MonoBehaviour {

	public float power;
	private int direction;
	public Transform upBorder;
	public Transform downBorder;
	public clubAction club;
	public Vector3 initPos;
	public bool moving = true;
	private int score = -15;
	// Use this for initialization
	void Start () {
		direction = 1;
	}
	
	// Update is called once per frame
	void Update () {
		if (power < 0)
			power = 0;
		if (power > 0) {
			moving = true;
			transform.Translate (Vector3.up * power * 7 * direction * Time.deltaTime);
			if (moving) {
				if (transform.position.y >= upBorder.position.y)
					direction = -1;
				else if (transform.position.y <= downBorder.position.y)
					direction = 1;
				power -= Time.deltaTime;
			}
		} else
			moving = false;
		if (moving == false) {
			if (transform.position.y > 3)
				direction = -1;
			else
				direction = 1;
			if (transform.position.y >= 2.70 && transform.position.y <= 3.45)
			{
				Destroy (gameObject);
				Debug.Log ("Score: " + score.ToString());
				Destroy (club);
			}
		}
	}

	public void DoSomething(float power)
	{
		if (moving == false) {
			score += 5;
			this.power = power;
		}
	}
}
