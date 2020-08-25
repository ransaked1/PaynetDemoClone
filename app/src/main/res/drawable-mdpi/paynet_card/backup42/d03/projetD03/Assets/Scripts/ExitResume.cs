using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class ExitResume : MonoBehaviour {

	public Button Resume;
	public Button Exit;
	public Button ExitSurely;
	public GameObject surescene;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		if (gameObject.tag == "resume")
			Resume.GetComponent<Button>().onClick.AddListener(TaskOnClick1);
		if (gameObject.tag == "exit")
			Exit.GetComponent<Button>().onClick.AddListener(TaskOnClick);
		if (gameObject.tag == "exitsure")
			ExitSurely.GetComponent<Button>().onClick.AddListener(TaskOnClick2);
	}

	void TaskOnClick1()
	{
		gameObject.transform.parent.gameObject.SetActive (false);
	}
	void TaskOnClick()
	{
		gameObject.transform.parent.gameObject.SetActive (false);
		surescene.SetActive(true);
	}
	void TaskOnClick2()
	{
		SceneManager.LoadScene("main", LoadSceneMode.Single);
	}
}
