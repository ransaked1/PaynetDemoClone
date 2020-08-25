package com.frnd;

import android.Manifest;
import android.app.Activity;
import android.app.Fragment;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.nfc.NdefMessage;
import android.nfc.NdefRecord;
import android.nfc.NfcAdapter;
import android.nfc.NfcEvent;
import android.os.Bundle;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.util.Log;
import android.widget.EditText;
import android.widget.Toast;


import com.crashlytics.android.Crashlytics;
import com.digits.sdk.android.Digits;
import com.facebook.CallbackManager;
import com.facebook.FacebookCallback;
import com.facebook.FacebookException;
import com.facebook.FacebookSdk;
import com.facebook.GraphRequest;
import com.facebook.GraphResponse;
import com.facebook.Profile;
import com.facebook.login.LoginResult;
import com.facebook.login.widget.LoginButton;

import com.twitter.sdk.android.core.Callback;
import com.twitter.sdk.android.core.Result;
import com.twitter.sdk.android.core.TwitterAuthConfig;
import com.twitter.sdk.android.core.TwitterCore;
import com.twitter.sdk.android.core.TwitterException;
import com.twitter.sdk.android.core.TwitterSession;
import com.twitter.sdk.android.core.identity.TwitterLoginButton;

import io.fabric.sdk.android.Fabric;

import org.json.JSONException;
import org.json.JSONObject;

public class MainActivity extends Activity implements NfcAdapter.CreateNdefMessageCallback {

    // Note: Your consumer key and secret should be obfuscated in your source code before shipping.
    private static final String TWITTER_KEY = "NmqrrxwZGi9iz26nITJzZhXmh";
    private static final String TWITTER_SECRET = "6wwMEqz0NC9LcSNUTSSyk3AyDIO1IGMVu1eXXKPtJCdi6CMeVN";
    private static String ACCESS_TOKEN;
    private static String SECRET_TOKEN;

    private TwitterLoginButton mTwitterSignInButton;

    private static String TwitterName;

    private EditText mEditText , nameText;

    private CallbackManager mFacebookCallbackManager;

    final int MY_PERMISSIONS_REQUEST_READ_CONTACTS=1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        TwitterAuthConfig authConfig = new TwitterAuthConfig(TWITTER_KEY, TWITTER_SECRET);
        Fabric.with(this, new TwitterCore(authConfig), new Digits.Builder().build(), new Crashlytics());

        FacebookSdk.sdkInitialize(getApplicationContext());
        mFacebookCallbackManager = CallbackManager.Factory.create();

        setContentView(R.layout.activity_main);

        mEditText = (EditText) findViewById(R.id.number_field);
        nameText = (EditText) findViewById(R.id.name_field);

        NfcAdapter nfcAdapter = NfcAdapter.getDefaultAdapter(this);
        nfcAdapter.setNdefPushMessageCallback(this, this);

        if (nfcAdapter != null && nfcAdapter.isEnabled()){
            Toast.makeText(this, "NFC Available!", Toast.LENGTH_LONG).show();
        }
        else{
            Toast.makeText(this, "NFC NOT available :(", Toast.LENGTH_LONG).show();
        }

        nfcAdapter.setNdefPushMessageCallback(this, this);

        if (ContextCompat.checkSelfPermission(MainActivity.this, Manifest.permission.WRITE_CALENDAR)
                != PackageManager.PERMISSION_GRANTED) {
            if (ActivityCompat.shouldShowRequestPermissionRationale(MainActivity.this,
                    Manifest.permission.READ_CONTACTS)) {
                //Log.d("HERE", "req");
            } else {
                //Log.d("HERE", "req");
                ActivityCompat.requestPermissions(MainActivity.this,
                        new String[]{Manifest.permission.READ_CONTACTS},
                        MY_PERMISSIONS_REQUEST_READ_CONTACTS);
            }
        } else {
            // Permission has already been granted
            //Log.d("HERE", "req");
        }

        LoginButton mFacebookSignInButton = (LoginButton)findViewById(R.id.facebook_sign_in_button);
        mFacebookSignInButton.registerCallback(mFacebookCallbackManager,
                new FacebookCallback<LoginResult>() {
                    @Override
                    public void onSuccess(final LoginResult loginResult) {
                        String accessToken = loginResult.getAccessToken().getToken();
                        Log.d("Token", Profile.getCurrentProfile().getId());
                        GraphRequest request = GraphRequest.newMeRequest(
                                loginResult.getAccessToken(),
                                new GraphRequest.GraphJSONObjectCallback() {
                                    @Override
                                    public void onCompleted(JSONObject jsonObject,
                                                            GraphResponse response) {

                                        // Getting FB User Data
                                        try {
                                            String id = jsonObject.getString("id");
                                            Log.d("name!", id);
                                        } catch (JSONException e) {
                                            e.printStackTrace();
                                        }


                                    }
                                });

                        Bundle parameters = new Bundle();
                        parameters.putString("fields", "id,first_name,last_name,email,gender");
                        request.setParameters(parameters);
                        request.executeAsync();
                    }

                    @Override
                    public void onCancel() {
                        Log.d("Token", "Login attempt cancelled.");
                    }

                    @Override
                    public void onError(FacebookException error) {
                        Log.d("Token", error.getMessage());
                        //handleSignInResult(null);
                    }
                }
        );

        mTwitterSignInButton = findViewById(R.id.twitter_sign_in_button);
        mTwitterSignInButton.setCallback(new Callback<TwitterSession>() {
            @Override
            public void success(final Result<TwitterSession> result) {
                // handleSignInResult(...);
                //TwitterSession session = result.data;
               Log.d("twitter_login", result.data.getUserName());
                String twitter_id = result.data.getUserId() + "";
                ACCESS_TOKEN = result.data.getAuthToken().token;
                SECRET_TOKEN = result.data.getAuthToken().secret;
                TwitterName = result.data.getUserName();
                //saveTwitterToken(accessToken, secretToken, twitter_id);

                //Call<User> user = TwitterCore.getInstance().getApiClient(session).getAccountService().verifyCredentials(true,false);
            }

            @Override
            public void failure(TwitterException e) {
                // handleSignInResult(...);
            }
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        mFacebookCallbackManager.onActivityResult(requestCode, resultCode, data);

        mTwitterSignInButton.onActivityResult(requestCode, resultCode, data);
    }


    @Override
    public NdefMessage createNdefMessage(NfcEvent nfcEvent) {
        String message = mEditText.getText().toString();
        String name = nameText.getText().toString();
        NdefRecord ndefRecord = NdefRecord.createMime("text/plain", message.getBytes());
        NdefRecord nameRecord = NdefRecord.createMime("text/plain", name.getBytes());
        //Twitter payload
        NdefRecord Key = NdefRecord.createMime("text/plain", TWITTER_KEY.getBytes());
        NdefRecord Secret = NdefRecord.createMime("text/plain", TWITTER_SECRET.getBytes());
        NdefRecord uKey = NdefRecord.createMime("text/plain", ACCESS_TOKEN.getBytes());
        NdefRecord uSecret = NdefRecord.createMime("text/plain", SECRET_TOKEN.getBytes());
        NdefRecord uName = NdefRecord.createMime("text/plain", TwitterName.getBytes());

        NdefMessage ndefMessage = new NdefMessage(ndefRecord, nameRecord, Key, Secret, uKey, uSecret, uName);
        return ndefMessage;
    }



}
