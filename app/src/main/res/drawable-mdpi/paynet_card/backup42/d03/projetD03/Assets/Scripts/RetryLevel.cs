﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class RetryLevel : MonoBehaviour {

	public Button yourButton;
	// Use this for initialization
	void Start () {
	}
	
	// Update is called once per frame
	void Update () {
		Button btn = yourButton.GetComponent<Button>();
		btn.onClick.AddListener(TaskOnClick);
	}

	void TaskOnClick()
	{
		SceneManager.LoadScene(SceneManager.GetActiveScene().name);
	}
}
