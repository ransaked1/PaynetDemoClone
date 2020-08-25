using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;


public class StartGame : MonoBehaviour {

	public Button yourButton;
//	private AssetBundle myLoadedAssetBundle;
//	private string[] scenePaths;
	public Texture2D cursor;
	private CursorMode cursorMode = CursorMode.Auto;
	private Vector2 hotSpot = new Vector2(0, 0);

	// Use this for initialization
	void Start () {
		Cursor.SetCursor (cursor, hotSpot, cursorMode);
	}
	
	// Update is called once per frame
	void Update () {
//		myLoadedAssetBundle = AssetBundle.LoadFromFile("Assets/Scenes");
//		scenePaths = myLoadedAssetBundle.GetAllScenePaths();
		Button btn = yourButton.GetComponent<Button>();
		btn.onClick.AddListener(TaskOnClick);

	}


	void TaskOnClick()
	{
		SceneManager.LoadScene("ex01", LoadSceneMode.Single);
	}
}
