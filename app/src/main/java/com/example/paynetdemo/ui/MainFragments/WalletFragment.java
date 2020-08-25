package com.example.paynetdemo.ui.MainFragments;

import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.example.paynetdemo.R;
import com.example.paynetdemo.ui.WalletActivities.Discount_card;
import com.example.paynetdemo.ui.WalletActivities.History;
import com.example.paynetdemo.ui.WalletActivities.Mybills;
import com.example.paynetdemo.ui.WalletActivities.Pay;
import com.example.paynetdemo.ui.WalletActivities.Topup;
import com.example.paynetdemo.ui.WalletActivities.Transfer;
import com.example.paynetdemo.ui.WalletActivities.Withdraw;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.cardview.widget.CardView;
import androidx.fragment.app.Fragment;

public class WalletFragment extends Fragment implements View.OnClickListener{

    private CardView btn_mybills, btn_pay, btn_transfer, btn_topup, btn_withdraw, btn_discount_card, btn_history;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater,
                             @Nullable ViewGroup container,
                             @Nullable Bundle savedInstanceState) {

        return inflater.inflate(R.layout.fragment_wallet, container, false);
    }

    @Override
    public void onViewCreated(View view, @Nullable Bundle savedInstanceState) {
        btn_mybills = (CardView)getView().findViewById(R.id.btn_mybills);
        btn_pay = (CardView)getView().findViewById(R.id.btn_pay);
        btn_transfer = (CardView)getView().findViewById(R.id.btn_transfer);
        btn_topup = (CardView)getView().findViewById(R.id.btn_topup);
        btn_withdraw = (CardView)getView().findViewById(R.id.btn_withdraw);
        btn_discount_card = (CardView)getView().findViewById(R.id.btn_discount_card);
        btn_history = (CardView)getView().findViewById(R.id.btn_history);

        btn_mybills.setOnClickListener(this);
        btn_pay.setOnClickListener(this);
        btn_transfer.setOnClickListener(this);
        btn_topup.setOnClickListener(this);
        btn_withdraw.setOnClickListener(this);
        btn_discount_card.setOnClickListener(this);
        btn_history.setOnClickListener(this);
    }

    @Override
    public void onClick(View view) {
        Intent i;

        switch (view.getId()){
            case R.id.btn_mybills: i = new Intent(getActivity(), Mybills.class); startActivity(i); break;
            case R.id.btn_pay: i = new Intent(getActivity(), Pay.class); startActivity(i); break;
            case R.id.btn_topup: i = new Intent(getActivity(), Topup.class); startActivity(i); break;
            case R.id.btn_transfer: i = new Intent(getActivity(), Transfer.class); startActivity(i); break;
            case R.id.btn_withdraw: i = new Intent(getActivity(), Withdraw.class); startActivity(i); break;
            case R.id.btn_discount_card: i = new Intent(getActivity(), Discount_card.class); startActivity(i); break;
            case R.id.btn_history: i = new Intent(getActivity(), History.class); startActivity(i); break;
            default: break;
        }

    }
}
