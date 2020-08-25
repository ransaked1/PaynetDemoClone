package com.example.paynetdemo;

import android.content.Intent;
import android.os.Build;
import android.os.Bundle;

import com.example.paynetdemo.ui.LoyaltyFragments.BottomSheetDialog;
import com.example.paynetdemo.ui.MainFragments.AccountFragment;
import com.example.paynetdemo.ui.MainFragments.AnalyticsFragment;
import com.example.paynetdemo.ui.MainFragments.LoyaltyFragment;
import com.example.paynetdemo.ui.MainFragments.WalletFragment;
import com.example.paynetdemo.ui.WalletActivities.Discount_card;
import com.example.paynetdemo.ui.WalletActivities.History;
import com.example.paynetdemo.ui.WalletActivities.Pay;
import com.example.paynetdemo.ui.WalletActivities.Topup;
import com.example.paynetdemo.ui.WalletActivities.Transfer;
import com.example.paynetdemo.ui.WalletActivities.Withdraw;
import com.google.android.material.navigation.NavigationView;
import com.google.android.material.tabs.TabLayout;

import androidx.annotation.NonNull;
import androidx.annotation.RequiresApi;
import androidx.appcompat.app.ActionBarDrawerToggle;
import androidx.appcompat.widget.Toolbar;

import androidx.core.view.GravityCompat;
import androidx.drawerlayout.widget.DrawerLayout;
import androidx.viewpager.widget.ViewPager;
import androidx.appcompat.app.AppCompatActivity;

import android.text.SpannableString;
import android.text.style.TextAppearanceSpan;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import com.example.paynetdemo.ui.MainFragments.SectionsPagerAdapter;

public class MainActivity extends AppCompatActivity implements NavigationView.OnNavigationItemSelectedListener, BottomSheetDialog.BottomSheetListener {

    private WalletFragment walletFragment;
    private LoyaltyFragment loyaltyFragment;
    private AnalyticsFragment analyticsFragment;
    private AccountFragment accountFragment;

    private DrawerLayout drawer;

    public TextView sectionTitle;
    public ViewPager viewPager;
    SectionsPagerAdapter sectionsPagerAdapter = new SectionsPagerAdapter(this, getSupportFragmentManager());

    @RequiresApi(api = Build.VERSION_CODES.M)
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        getSupportActionBar().setTitle(null);
        getSupportActionBar().setHomeButtonEnabled(true);
        getSupportActionBar().setDisplayHomeAsUpEnabled(true);
        getSupportActionBar().setHomeAsUpIndicator(R.drawable.ic_menu);

        drawer = findViewById(R.id.drawer_layout);
        ActionBarDrawerToggle toggle = new ActionBarDrawerToggle(this, drawer, toolbar,
                R.string.navigation_drawer_open, R.string.navigation_drawer_close);
        toggle.getDrawerArrowDrawable().setColor(getColor(R.color.tab_unselected));
        drawer.addDrawerListener(toggle);
        toggle.syncState();

        sectionTitle = (TextView)findViewById(R.id.sectionTitle);

        walletFragment = new WalletFragment();
        loyaltyFragment = new LoyaltyFragment();
        analyticsFragment = new AnalyticsFragment();
        accountFragment = new AccountFragment();

        sectionsPagerAdapter.addFragment(walletFragment);
        sectionsPagerAdapter.addFragment(loyaltyFragment);
        sectionsPagerAdapter.addFragment(analyticsFragment);
        sectionsPagerAdapter.addFragment(accountFragment);

        viewPager = findViewById(R.id.view_pager);
        TabLayout tabs = findViewById(R.id.tabs);
        viewPager.setAdapter(sectionsPagerAdapter);
        tabs.setupWithViewPager(viewPager);

        tabs.getTabAt(0).setIcon(R.drawable.ic_wallet);
        tabs.getTabAt(1).setIcon(R.drawable.ic_percent);
        tabs.getTabAt(2).setIcon(R.drawable.ic_piechart);
        tabs.getTabAt(3).setIcon(R.drawable.ic_account);

        ViewGroup slidingTabs = (ViewGroup) tabs.getChildAt(0);
        View v = slidingTabs.getChildAt(1);
        ViewGroup.MarginLayoutParams params = (ViewGroup.MarginLayoutParams)v.getLayoutParams();
        params.rightMargin = 140;

        sectionTitle.setText(R.string.tab_text_wallet);

        final NavigationView navigationView = (NavigationView) findViewById(R.id.nav_view);
        Menu menu = navigationView.getMenu();

        MenuItem tools= menu.findItem(R.id.drawer_operations);
        SpannableString s = new SpannableString(tools.getTitle());
        s.setSpan(new TextAppearanceSpan(this, R.style.DrawerSectionAppearance), 0, s.length(), 0);
        tools.setTitle(s);
        navigationView.setNavigationItemSelectedListener(this);

        tools = menu.findItem(R.id.nav_version);
        s = new SpannableString(tools.getTitle());
        s.setSpan(new TextAppearanceSpan(this, R.style.DrawerVersionAppearance), 0, s.length(), 0);
        tools.setTitle(s);
        navigationView.setNavigationItemSelectedListener(this);

        if (savedInstanceState == null) {
            navigationView.setCheckedItem(R.id.nav_wallet);
        }

        viewPager.addOnPageChangeListener(new ViewPager.OnPageChangeListener() {
            @Override
            public void onPageScrolled(int position, float positionOffset, int positionOffsetPixels) {

            }

            @Override
            public void onPageSelected(int position) {
                TextView sectionTitle = (TextView)findViewById(R.id.sectionTitle);
                switch (viewPager.getCurrentItem()) {
                    case 0:
                        sectionTitle.setText(R.string.tab_text_wallet);
                        navigationView.setCheckedItem(R.id.nav_wallet);
                        break;
                    case 1:
                        sectionTitle.setText(R.string.tab_text_loyalty);
                        navigationView.setCheckedItem(R.id.nav_loyalty);
                        break;
                    case 2:
                        sectionTitle.setText(R.string.tab_text_analytics);
                        navigationView.setCheckedItem(R.id.nav_analytics);
                        break;
                    case 3:
                        sectionTitle.setText(R.string.tab_text_account);
                        navigationView.setCheckedItem(R.id.nav_account);
                        break;
                }
            }

            @Override
            public void onPageScrollStateChanged(int state) {

            }
        });
    }

    @Override
    public void onBackPressed() {
        if (drawer.isDrawerOpen(GravityCompat.START)) {
            drawer.closeDrawer(GravityCompat.START);
        } else {
            super.onBackPressed();
        }
    }

    @Override
    public boolean onNavigationItemSelected(@NonNull MenuItem item) {
        Intent i;
        switch (item.getItemId()){
            case R.id.nav_wallet:
                viewPager.setCurrentItem(0);
                break;
            case R.id.nav_cart:
                break;
            case R.id.nav_loyalty:
                viewPager.setCurrentItem(1);
                break;
            case R.id.nav_history:
                i = new Intent(this, History.class);
                startActivity(i);
                break;
            case R.id.nav_statement:
                break;
            case R.id.nav_analytics:
                viewPager.setCurrentItem(2);
                break;
            case R.id.nav_account:
                viewPager.setCurrentItem(3);
                break;
            case R.id.nav_pay:
                i = new Intent(this, Pay.class);
                startActivity(i);
                break;
            case R.id.nav_transfer:
                i = new Intent(this, Transfer.class);
                startActivity(i);
                break;
            case R.id.nav_topup:
                i = new Intent(this, Topup.class);
                startActivity(i);
                break;
            case R.id.nav_withdraw:
                i = new Intent(this, Withdraw.class);
                startActivity(i);
                break;
            case R.id.nav_NFC:
                break;
            case R.id.nav_loyalty_card:
                i = new Intent(this, Discount_card.class);
                startActivity(i);
                break;
            case R.id.nav_logout:
                System.exit(0);
                break;
        }

        drawer.closeDrawer(GravityCompat.START);

        return true;
    }

    @Override
    public void onButtonClicked(String text) {
        loyaltyFragment.tabLayout.getTabAt(3).setText(text);
        loyaltyFragment.tabLayout.getTabAt(2).select();
    }
}
