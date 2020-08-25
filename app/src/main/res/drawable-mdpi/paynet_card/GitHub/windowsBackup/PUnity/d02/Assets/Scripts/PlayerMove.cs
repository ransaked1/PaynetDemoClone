using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMove : MonoBehaviour {

	public Vector3 newPosition;
	public GameObject up;
	public GameObject up2;
	public GameObject right;
	public GameObject down2;
	public GameObject down;
	public int direction;
	public bool active = false;
	private bool moving = false;

	// Use this for initialization
	void Start () {
		newPosition = transform.position;
		active = false;
	}

	// Update is called once per frame
	void Update () {
		if (Input.GetMouseButtonDown (0) && active == true) {
			GameObject.Find ("Audio").GetComponent<AudioSource> ().Play ();
			newPosition = Camera.main.ScreenToWorldPoint (Input.mousePosition);
			newPosition.z = transform.position.z;
			if (newPosition.y < transform.position.y && newPosition.x - transform.position.x < 0.3f)
				direction = 1;
			if (newPosition.y < transform.position.y && newPosition.x - transform.position.x > 0.3f)
				direction = 2;
			if (newPosition.x > transform.position.x && newPosition.y - transform.position.y < 0.4f && newPosition.y - transform.position.y > -0.4f)
				direction = 3;
			if (newPosition.y > transform.position.y && newPosition.x - transform.position.x > 0.4f)
				direction = 4;
			if (newPosition.y > transform.position.y && newPosition.x - transform.position.x < 0.4f)
				direction = 5;
			if (newPosition.y < transform.position.y && newPosition.x - transform.position.x < -0.3f)
				direction = 6;
			if (newPosition.x < transform.position.x && newPosition.y - transform.position.y < 0.4f && newPosition.y - transform.position.y > -0.4f)
				direction = 7;
			if (newPosition.y > transform.position.y && newPosition.x - transform.position.x < -0.4f)
				direction = 8;
			moving = true;
		}
//		if (active == false)
//			moving = false;
		if (direction == 1 && moving == false) {
			up.SetActive (false);
			up2.SetActive (false);
			right.SetActive (false);
			down2.SetActive (false);
			GetComponent<SpriteRenderer>().enabled = true;
			down.GetComponent<Animator>().SetBool("move", false);
		}
		if (direction == 1 && moving == true) {
			up.SetActive (false);
			up2.SetActive (false);
			right.SetActive (false);
			down2.SetActive (false);
			GetComponent<SpriteRenderer>().enabled = true;
			down.GetComponent<Animator>().SetBool("move", true);
		}
		if (direction == 2 && moving == false) {
			up.SetActive (false);
			up2.SetActive (false);
			right.SetActive (false);
			down2.SetActive (true);
			down2.GetComponent<SpriteRenderer>().flipX = false;
			GetComponent<SpriteRenderer>().enabled = false;
			down2.GetComponent<Animator>().SetBool("move", false);
		}
		if (direction == 2 && moving == true) {
			up.SetActive (false);
			up2.SetActive (false);
			right.SetActive (false);
			down2.SetActive (true);
			down2.GetComponent<SpriteRenderer>().flipX = false;
			GetComponent<SpriteRenderer>().enabled = false;
			down2.GetComponent<Animator>().SetBool("move", true);
		}
		if (direction == 3 && moving == false) {
			up.SetActive (false);
			up2.SetActive (false);
			right.SetActive (true);
			down2.SetActive (false);
			right.GetComponent<SpriteRenderer>().flipX = false;
			GetComponent<SpriteRenderer>().enabled = false;
			right.GetComponent<Animator>().SetBool("move", false);
		}
		if (direction == 3 && moving == true) {
			up.SetActive (false);
			up2.SetActive (false);
			right.SetActive (true);
			down2.SetActive (false);
			right.GetComponent<SpriteRenderer>().flipX = false;
			GetComponent<SpriteRenderer>().enabled = false;
			right.GetComponent<Animator>().SetBool("move", true);
		}
		if (direction == 4 && moving == false) {
			up.SetActive (false);
			up2.SetActive (true);
			right.SetActive (false);
			down2.SetActive (false);
			up2.GetComponent<SpriteRenderer>().flipX = false;
			GetComponent<SpriteRenderer>().enabled = false;
			up2.GetComponent<Animator>().SetBool("move", false);
		}
		if (direction == 4 && moving == true) {
			up.SetActive (false);
			up2.SetActive (true);
			right.SetActive (false);
			down2.SetActive (false);
			up2.GetComponent<SpriteRenderer>().flipX = false;
			GetComponent<SpriteRenderer>().enabled = false;
			up2.GetComponent<Animator>().SetBool("move", true);
		}
		if (direction == 5 && moving == false) {
			up.SetActive (true);
			up2.SetActive (false);
			right.SetActive (false);
			down2.SetActive (false);
			GetComponent<SpriteRenderer>().enabled = false;
			up.GetComponent<Animator>().SetBool("move", false);
		}
		if (direction == 5 && moving == true) {
			up.SetActive (true);
			up2.SetActive (false);
			right.SetActive (false);
			down2.SetActive (false);
			GetComponent<SpriteRenderer>().enabled = false;
			up.GetComponent<Animator>().SetBool("move", true);
		}
		if (direction == 6 && moving == false) {
			up.SetActive (false);
			up2.SetActive (false);
			right.SetActive (false);
			down2.SetActive (true);
			down2.GetComponent<SpriteRenderer>().flipX = true;
			GetComponent<SpriteRenderer>().enabled = false;
			down2.GetComponent<Animator>().SetBool("move", false);
		}
		if (direction == 6 && moving == true) {
			up.SetActive (false);
			up2.SetActive (false);
			right.SetActive (false);
			down2.SetActive (true);
			down2.GetComponent<SpriteRenderer>().flipX = true;
			GetComponent<SpriteRenderer>().enabled = false;
			down2.GetComponent<Animator>().SetBool("move", true);
		}
		if (direction == 7 && moving == false) {
			up.SetActive (false);
			up2.SetActive (false);
			right.SetActive (true);
			down2.SetActive (false);
			right.GetComponent<SpriteRenderer>().flipX = true;
			GetComponent<SpriteRenderer>().enabled = false;
			right.GetComponent<Animator>().SetBool("move", false);
		}
		if (direction == 7 && moving == true) {
			up.SetActive (false);
			up2.SetActive (false);
			right.SetActive (true);
			down2.SetActive (false);
			right.GetComponent<SpriteRenderer>().flipX = true;
			GetComponent<SpriteRenderer>().enabled = false;
			right.GetComponent<Animator>().SetBool("move", true);
		}
		if (direction == 8 && moving == false) {
			up.SetActive (false);
			up2.SetActive (true);
			right.SetActive (false);
			down2.SetActive (false);
			up2.GetComponent<SpriteRenderer>().flipX = true;
			GetComponent<SpriteRenderer>().enabled = false;
			up2.GetComponent<Animator>().SetBool("move", false);
		}
		if (direction == 8 && moving == true) {
			up.SetActive (false);
			up2.SetActive (true);
			right.SetActive (false);
			down2.SetActive (false);
			up2.GetComponent<SpriteRenderer>().flipX = true;
			GetComponent<SpriteRenderer>().enabled = false;
			up2.GetComponent<Animator>().SetBool("move", true);
		}
		up.transform.position = Vector3.MoveTowards(transform.position, newPosition, 1.5f * Time.deltaTime);
		up2.transform.position = Vector3.MoveTowards(transform.position, newPosition, 1.5f * Time.deltaTime);
		right.transform.position = Vector3.MoveTowards(transform.position, newPosition, 1.5f * Time.deltaTime);
		down2.transform.position = Vector3.MoveTowards(transform.position, newPosition, 1.5f * Time.deltaTime);
		down.transform.position = Vector3.MoveTowards(transform.position, newPosition, 1.5f * Time.deltaTime);
		if (Mathf.Approximately (transform.position.x, newPosition.x) && Mathf.Approximately (transform.position.y, newPosition.y))
			moving = false;
	}
}
