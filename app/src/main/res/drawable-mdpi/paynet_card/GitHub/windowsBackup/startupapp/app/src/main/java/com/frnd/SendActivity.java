package com.frnd;

import android.app.Activity;
import android.content.ContentUris;
import android.content.ContentValues;
import android.content.Intent;
import android.net.Uri;
import android.nfc.NdefMessage;
import android.nfc.NfcAdapter;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Parcelable;
import android.provider.ContactsContract;
import android.util.Log;
import android.widget.TextView;

import twitter4j.Twitter;
import twitter4j.TwitterFactory;
import twitter4j.auth.AccessToken;
import twitter4j.conf.ConfigurationBuilder;

import com.twitter.sdk.android.core.Callback;
import com.twitter.sdk.android.core.Result;
import com.twitter.sdk.android.core.TwitterAuthConfig;
import com.twitter.sdk.android.core.TwitterCore;
import com.twitter.sdk.android.core.TwitterException;
import com.twitter.sdk.android.core.TwitterSession;
import com.twitter.sdk.android.core.identity.TwitterLoginButton;

public class SendActivity extends Activity {

    public static final String EXTRA_MESSAGE = "com.startupapp.MESSAGE";
    private TextView mTextView;
    public String msg, name, Key, Secret, uName, uKey, uSecret;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_send);
        mTextView = findViewById(R.id.text_view);
    }

    @Override
    protected void onResume(){
        super.onResume();

        Intent intent = getIntent();
        if (NfcAdapter.ACTION_NDEF_DISCOVERED.equals(intent.getAction())) {
            Parcelable[] rawMessages = intent.getParcelableArrayExtra(
                    NfcAdapter.EXTRA_NDEF_MESSAGES);

            NdefMessage message = (NdefMessage) rawMessages[0]; // only one message transferred
            mTextView.setText(new String(message.getRecords()[0].getPayload()));

            msg = new String(message.getRecords()[0].getPayload());
            name = new String(message.getRecords()[1].getPayload());

            Key = new String(message.getRecords()[2].getPayload());
            Secret = new String(message.getRecords()[3].getPayload());
            uKey = new String(message.getRecords()[4].getPayload());
            uSecret = new String(message.getRecords()[5].getPayload());
            uName = new String(message.getRecords()[6].getPayload());

            sendMessage();
            new MakeFriend().execute(uKey, uSecret, Key, Secret, uName);
        }
        else {
            mTextView.setText("Contact Added!");
        }
    }

    public void addTwitter() throws twitter4j.TwitterException {

    }

    public void sendMessage() {

        Intent sintent = new Intent(this, SendActivity.class);
        String message = msg;
        sintent.putExtra(EXTRA_MESSAGE, message);

        Uri addContactsUri = ContactsContract.Data.CONTENT_URI;

        // Add an empty contact and get the generated id.
        long rowContactId = getRawContactId();

        // Add contact name data.
        String displayName = name;
        insertContactDisplayName(addContactsUri, rowContactId, displayName);

        // Add contact phone data.
        String phoneNumber = mTextView.getText().toString();
        String phoneTypeStr = mTextView.getText().toString();
        insertContactPhoneNumber(addContactsUri, rowContactId, phoneNumber, phoneTypeStr);
        finish();

        addPhone(message);
        startActivity(sintent);
    }

    private long getRawContactId(){
        ContentValues contentValues = new ContentValues();
        Uri rawContactUri = getContentResolver().insert(ContactsContract.RawContacts.CONTENT_URI, contentValues);
        // Get the newly created contact raw id.
        long ret = ContentUris.parseId(rawContactUri);
        return ret;
    }

    private void insertContactDisplayName(Uri addContactsUri, long rawContactId, String displayName)
    {
        ContentValues contentValues = new ContentValues();

        contentValues.put(ContactsContract.Data.RAW_CONTACT_ID, rawContactId);

        // Each contact must has an mime type to avoid java.lang.IllegalArgumentException: mimetype is required error.
        contentValues.put(ContactsContract.Data.MIMETYPE, ContactsContract.CommonDataKinds.StructuredName.CONTENT_ITEM_TYPE);

        // Put contact display name value.
        contentValues.put(ContactsContract.CommonDataKinds.StructuredName.GIVEN_NAME, displayName);

        getContentResolver().insert(addContactsUri, contentValues);

    }

    public void addPhone(String nr){
        Log.d("My app", nr);
    }

    private void insertContactPhoneNumber(Uri addContactsUri, long rawContactId, String phoneNumber, String phoneTypeStr)
    {
        // Create a ContentValues object.
        ContentValues contentValues = new ContentValues();

        // Each contact must has an id to avoid java.lang.IllegalArgumentException: raw_contact_id is required error.
        contentValues.put(ContactsContract.Data.RAW_CONTACT_ID, rawContactId);

        // Each contact must has an mime type to avoid java.lang.IllegalArgumentException: mimetype is required error.
        contentValues.put(ContactsContract.Data.MIMETYPE, ContactsContract.CommonDataKinds.Phone.CONTENT_ITEM_TYPE);

        // Put phone number value.
        contentValues.put(ContactsContract.CommonDataKinds.Phone.NUMBER, phoneNumber);

        // Calculate phone type by user selection.
        int phoneContactType = ContactsContract.CommonDataKinds.Phone.TYPE_HOME;

        if("home".equalsIgnoreCase(phoneTypeStr))
        {
            phoneContactType = ContactsContract.CommonDataKinds.Phone.TYPE_HOME;
        }else if("mobile".equalsIgnoreCase(phoneTypeStr))
        {
            phoneContactType = ContactsContract.CommonDataKinds.Phone.TYPE_MOBILE;
        }else if("work".equalsIgnoreCase(phoneTypeStr))
        {
            phoneContactType = ContactsContract.CommonDataKinds.Phone.TYPE_WORK;
        }
        // Put phone type value.
        contentValues.put(ContactsContract.CommonDataKinds.Phone.TYPE, phoneContactType);

        // Insert new contact data into phone contact list.
        getContentResolver().insert(addContactsUri, contentValues);

    }
}

class MakeFriend extends AsyncTask<String, Integer, Long> {

    protected Long doInBackground(String... params) {

        String uKey = "982691337110740992-en0AGaQhD8JoxzTr0i8uPh1ZmNNNT9r";//params[0];
        String uSecret = "Sv93YbbdUnnc8KZn6gHWBIGruTb0wi2Q8l5hPe5Hd28tZ";//params[1];
        String Key = params[2];
        String Secret = params[3];
        String uName = params[4];

        Log.d("Wtf", uKey);
        Log.d("Wtf", uSecret);
        Log.d("Wtf", Key);
        Log.d("Wtf", Secret);
        Log.d("Wtf", uName);

        ConfigurationBuilder cb = new ConfigurationBuilder();
        cb.setDebugEnabled(true)
                .setOAuthConsumerKey(Key)
                .setOAuthConsumerSecret(Secret)
                .setOAuthAccessToken(uKey)
                .setOAuthAccessTokenSecret(uSecret);

        TwitterFactory tf = new TwitterFactory(cb.build());

        Twitter twitter = tf.getInstance();
        try {
            twitter4j.User  user = twitter.createFriendship(uName);
        } catch (twitter4j.TwitterException e) {
            e.printStackTrace();
        }

        return Long.valueOf(1);
    }

    protected void onProgressUpdate(Integer... progress) {
    }

    protected void onPostExecute(Long result) {

    }
}
