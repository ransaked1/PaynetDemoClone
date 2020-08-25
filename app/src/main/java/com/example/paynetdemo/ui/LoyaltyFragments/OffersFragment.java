package com.example.paynetdemo.ui.LoyaltyFragments;

import android.content.Context;
import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.GridLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.example.paynetdemo.R;

import java.util.ArrayList;
import java.util.List;

public class OffersFragment extends Fragment {

    List<Card> lstCard;
    Context context;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment

        context = container.getContext();

        return inflater.inflate(R.layout.fragment_offers, container, false);
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        lstCard = new ArrayList<>();
        lstCard.add(new Card("5% Cashback", R.drawable.card_discount));
        lstCard.add(new Card("10% Cashback", R.drawable.card_discount));
        lstCard.add(new Card("10% Cashback", R.drawable.card_discount));
        lstCard.add(new Card("5% Cashback", R.drawable.card_discount));
        lstCard.add(new Card("10% Cashback", R.drawable.card_discount));
        lstCard.add(new Card("5% Cashback", R.drawable.card_discount));
        lstCard.add(new Card("10% Cashback", R.drawable.card_discount));
        lstCard.add(new Card("10% Cashback", R.drawable.card_discount));
        lstCard.add(new Card("5% Cashback", R.drawable.card_discount));
        lstCard.add(new Card("10% Cashback", R.drawable.card_discount));
        lstCard.add(new Card("5% Cashback", R.drawable.card_discount));
        lstCard.add(new Card("10% Cashback", R.drawable.card_discount));
        lstCard.add(new Card("10% Cashback", R.drawable.card_discount));
        lstCard.add(new Card("5% Cashback", R.drawable.card_discount));
        lstCard.add(new Card("10% Cashback", R.drawable.card_discount));
        lstCard.add(new Card("5% Cashback", R.drawable.card_discount));
        lstCard.add(new Card("10% Cashback", R.drawable.card_discount));
        lstCard.add(new Card("10% Cashback", R.drawable.card_discount));
        lstCard.add(new Card("5% Cashback", R.drawable.card_discount));
        lstCard.add(new Card("10% Cashback", R.drawable.card_discount));

        RecyclerView rv = (RecyclerView) getView().findViewById(R.id.recycler_view);
        RecyclerViewAdapter adapter = new RecyclerViewAdapter(context, lstCard);
        rv.setLayoutManager(new GridLayoutManager(context, 3));
        rv.setAdapter(adapter);
    }
}