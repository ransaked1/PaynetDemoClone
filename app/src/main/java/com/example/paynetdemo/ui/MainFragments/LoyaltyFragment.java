package com.example.paynetdemo.ui.MainFragments;

import android.content.Context;
import android.content.Intent;
import android.graphics.Color;
import android.graphics.ColorMatrix;
import android.graphics.ColorMatrixColorFilter;
import android.os.Bundle;
import android.os.Debug;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toolbar;

import com.example.paynetdemo.CustomViewPager;
import com.example.paynetdemo.R;

import androidx.cardview.widget.CardView;
import androidx.fragment.app.Fragment;

import com.example.paynetdemo.ui.LoyaltyFragments.BottomSheetDialog;
import com.example.paynetdemo.ui.LoyaltyFragments.HistoryFragment;
import com.example.paynetdemo.ui.LoyaltyFragments.OffersFragment;
import com.example.paynetdemo.ui.LoyaltyFragments.PartnersFragment;
import com.example.paynetdemo.ui.WalletActivities.Discount_card;
import com.google.android.material.card.MaterialCardView;
import com.google.android.material.tabs.TabLayout;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentPagerAdapter;
import androidx.localbroadcastmanager.content.LocalBroadcastManager;
import androidx.viewpager.widget.ViewPager;
import androidx.viewpager2.widget.ViewPager2;

public class LoyaltyFragment extends Fragment implements View.OnClickListener, BottomSheetDialog.BottomSheetListener {

    private OffersFragment offersFragment;
    private PartnersFragment partnersFragment;
    private HistoryFragment historyFragment;
    private HistoryFragment dummyHistoryFragment;
    BottomSheetDialog bottomSheetDialog;

    SectionPagerAdapter sectionsPagerAdapter;

    public TabLayout tabLayout;

    CustomViewPager viewPager;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater,
                             @Nullable ViewGroup container,
                             @Nullable Bundle savedInstanceState) {
        final FragmentManager fragmentManager = getFragmentManager();

        View view = inflater.inflate(R.layout.fragment_loyalty, container, false);
        return view;
    }

    public void onViewCreated(View view, @Nullable Bundle savedInstanceState) {


        MaterialCardView btn_discount_card = (MaterialCardView)getView().findViewById(R.id.btn_discount_card);
        ImageView img = (ImageView)getView().findViewById(R.id.card_img);

        btn_discount_card.setOnClickListener(this);
        img.setColorFilter(Color.argb(130,20,20,20));

        //Toolbar toolbar = (Toolbar)getView().findViewById(R.id.tab_layout);

        viewPager = (CustomViewPager) getView().findViewById(R.id.view_pager);
        tabLayout = getView().findViewById(R.id.tab_layout);

        viewPager.addOnPageChangeListener(new ViewPager.OnPageChangeListener() {
            @Override
            public void onPageScrolled(int position, float positionOffset, int positionOffsetPixels) {

            }

            @Override
            public void onPageSelected(int position) {
                switch (viewPager.getCurrentItem()) {
                    case 0:
                        ((ViewGroup) tabLayout.getChildAt(0)).getChildAt(3).setVisibility(View.INVISIBLE);
                        break;
                    case 1:
                        ((ViewGroup) tabLayout.getChildAt(0)).getChildAt(3).setVisibility(View.INVISIBLE);
                        break;
                    case 2:
                        ((ViewGroup) tabLayout.getChildAt(0)).getChildAt(3).setVisibility(View.VISIBLE);
                        break;
                    case 3:
                        bottomSheetDialog = new BottomSheetDialog();
                        bottomSheetDialog.setOriginalText((String) tabLayout.getTabAt(3).getText());
                        bottomSheetDialog.setCancelable(false);
                        bottomSheetDialog.show(getParentFragmentManager(), "bottomSheet");
                        break;
                }
            }

            @Override
            public void onPageScrollStateChanged(int state) {

            }
        });

        offersFragment = new OffersFragment();
        partnersFragment = new PartnersFragment();
        historyFragment = new HistoryFragment();
        dummyHistoryFragment = new HistoryFragment();

        sectionsPagerAdapter = new SectionPagerAdapter(getChildFragmentManager(),0);
        sectionsPagerAdapter.addFragment(offersFragment);
        sectionsPagerAdapter.addFragment(partnersFragment);
        sectionsPagerAdapter.addFragment(historyFragment);
        sectionsPagerAdapter.addFragment(dummyHistoryFragment);
        viewPager.setAdapter(sectionsPagerAdapter);
        tabLayout.setupWithViewPager(viewPager);

        tabLayout.getTabAt(0).setText("Offers");
        tabLayout.getTabAt(1).setText("Partners");
        tabLayout.getTabAt(2).setText("History");
        tabLayout.getTabAt(3).setText("Today ▼");

        ((ViewGroup) tabLayout.getChildAt(0)).getChildAt(3).setVisibility(View.INVISIBLE);

        LinearLayout layout = ((LinearLayout) ((LinearLayout) tabLayout.getChildAt(0)).getChildAt(0));
        LinearLayout.LayoutParams layoutParams = (LinearLayout.LayoutParams) layout.getLayoutParams();
        layoutParams.weight = 0.75f; // e.g. 0.5f
        layout.setLayoutParams(layoutParams);

        layout = ((LinearLayout) ((LinearLayout) tabLayout.getChildAt(0)).getChildAt(1));
        layoutParams = (LinearLayout.LayoutParams) layout.getLayoutParams();
        layoutParams.weight = 0.90f; // e.g. 0.5f
        layout.setLayoutParams(layoutParams);

        layout = ((LinearLayout) ((LinearLayout) tabLayout.getChildAt(0)).getChildAt(2));
        layoutParams = (LinearLayout.LayoutParams) layout.getLayoutParams();
        layoutParams.weight = 0.75f; // e.g. 0.5f
        layout.setLayoutParams(layoutParams);

    }

    @Override
    public void onClick(View view) {
        Intent i;

         i = new Intent(getActivity(), Discount_card.class);
         startActivity(i);
    }

    @Override
    public void onButtonClicked(String text) {
    }
}