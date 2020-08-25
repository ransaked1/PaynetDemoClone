package com.example.paynetdemo.ui.MainFragments;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.core.content.ContextCompat;
import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import com.example.paynetdemo.MainActivity;
import com.example.paynetdemo.R;
import com.example.paynetdemo.ui.AccountActivities.EditActivity;
import com.example.paynetdemo.ui.AccountActivities.FaqActivity;
import com.example.paynetdemo.ui.AccountActivities.IdentificationActivity;
import com.example.paynetdemo.ui.AccountActivities.LoyaltyActivity;
import com.example.paynetdemo.ui.AccountActivities.OnboardingActivity;
import com.example.paynetdemo.ui.AccountActivities.SettingsActivity;
import com.example.paynetdemo.ui.AccountActivities.SupportActivity;
import com.example.paynetdemo.ui.AccountActivities.TermsCondActivity;
import com.example.paynetdemo.ui.WalletActivities.Mybills;
import com.example.paynetdemo.ui.WalletActivities.Pay;

public class AccountFragment extends Fragment {

    String mTitle[] = new String[] {"Terms & Conditions", "FAQ", "Onboarding", "Your Loyalty Cards", "Support",
    "Settings", "Identification", "Log out"};
    int imgs[] = {R.drawable.terms_conditions, R.drawable.faq,R.drawable.diamond, R.drawable.your_loyalty,
            R.drawable.support,R.drawable.settings,R.drawable.identification,R.drawable.ic_logout};

    public AccountFragment() {
        // Required empty public constructor
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        return inflater.inflate(R.layout.fragment_account, container, false);
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        TextView textView = (TextView) getActivity().findViewById(R.id.edit_button);

        textView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getActivity(), EditActivity.class);
                startActivity(intent);
            }
        });

        ListView listView = (ListView) getView().findViewById(R.id.list_view);

        CustomAdapter adapter = new CustomAdapter(getContext(), mTitle, imgs);
        listView.setAdapter(adapter);

        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                Intent intent;

                switch (i){
                    case 0:  intent = new Intent(getActivity(), TermsCondActivity.class); startActivity(intent); break;
                    case 1:  intent = new Intent(getActivity(), FaqActivity.class); startActivity(intent); break;
                    case 2:  intent = new Intent(getActivity(), OnboardingActivity.class); startActivity(intent); break;
                    case 3:  intent = new Intent(getActivity(), LoyaltyActivity.class); startActivity(intent); break;
                    case 4:  intent = new Intent(getActivity(), SupportActivity.class); startActivity(intent); break;
                    case 5:  intent = new Intent(getActivity(), SettingsActivity.class); startActivity(intent); break;
                    case 6:  intent = new Intent(getActivity(), IdentificationActivity.class); startActivity(intent); break;
                    case 7:  System.exit(0); break;
                }
            }
        });

    }

    class CustomAdapter extends ArrayAdapter<String>{
        Context context;
        String rTitle[];
        int rImages[];

        CustomAdapter(Context c, String title[], int images[]){
            super(c, R.layout.list_row, R.id.text_menu,title);
            this.context = c;
            this.rTitle = title;
            this.rImages = images;
        }

        @NonNull
        @Override
        public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
            LayoutInflater layoutInflater = (LayoutInflater) getContext().getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            View row = layoutInflater.inflate(R.layout.list_row, parent, false);

            ImageView images = row.findViewById(R.id.image_menu);
            TextView title = row.findViewById(R.id.text_menu);

            images.setImageDrawable(ContextCompat.getDrawable(context, rImages[position]));
            title.setText(rTitle[position]);

            return row;
        }
    }
}