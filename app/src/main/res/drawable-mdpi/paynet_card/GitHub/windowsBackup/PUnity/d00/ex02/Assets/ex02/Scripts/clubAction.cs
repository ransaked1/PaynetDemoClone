using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class clubAction : MonoBehaviour {

	public float power = 0;

	private bool action = false;
	public Transform clubTransform;
	public ballAction ball;
	private Vector3 initPos;
	private bool boolean;
	private bool drag;

	//float tiltAroundZ = Input.GetAxis("Horizontal") * 180;
	//float tiltAroundX = Input.GetAxis("Vertical") * tiltAngle;
	Quaternion target = Quaternion.Euler(0, 180, 180);
	Quaternion target2 = Quaternion.Euler(0, 0, 0);

	// Use this for initialization
	void Start () {
		initPos = clubTransform.position;
		drag = false;
	}
		
	// Update is called once per frame
	void Update ()
	{
		boolean = false;
		if (ball.power == 0 && power == 0) {
			if (ball.transform.position.y > 3) {
				transform.position = new Vector3 (-0.35f, ball.transform.position.y - 0.2f, 0);
				transform.rotation = Quaternion.Slerp (transform.rotation, target, Time.deltaTime);
			} else {
				transform.position = new Vector3 (-0.35f, ball.transform.position.y + 0.2f, 0);
				transform.rotation = Quaternion.Slerp (transform.rotation, target2, Time.deltaTime);
			}
			initPos = transform.position;
		}
		if (Input.GetKey (KeyCode.Space) && ball.power == 0) {
			power += Time.deltaTime;
			power = Mathf.Clamp (power, 0.3F, 3.0F);
			transform.Translate (Vector3.down * Time.deltaTime);
			drag = true;
			boolean = true;
		}
		if (power == 3)
			boolean = false;
		if (!boolean && drag == true) {
			clubTransform.position = initPos;
			ball.DoSomething (power);
			power = 0;
			drag = false;
		}
	}
}
