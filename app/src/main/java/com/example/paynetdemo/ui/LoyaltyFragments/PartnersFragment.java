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

public class PartnersFragment extends Fragment {

    List<Card2> lstCard;
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
        lstCard.add(new Card2(R.drawable.logo1));
        lstCard.add(new Card2(R.drawable.logo2));
        lstCard.add(new Card2(R.drawable.logo3));
        lstCard.add(new Card2(R.drawable.logo4));
        lstCard.add(new Card2(R.drawable.logo1));
        lstCard.add(new Card2(R.drawable.logo2));
        lstCard.add(new Card2(R.drawable.logo3));
        lstCard.add(new Card2(R.drawable.logo4));
        lstCard.add(new Card2(R.drawable.logo1));
        lstCard.add(new Card2(R.drawable.logo2));
        lstCard.add(new Card2(R.drawable.logo3));
        lstCard.add(new Card2(R.drawable.logo4));
        lstCard.add(new Card2(R.drawable.logo1));
        lstCard.add(new Card2(R.drawable.logo2));
        lstCard.add(new Card2(R.drawable.logo3));
        lstCard.add(new Card2(R.drawable.logo4));

        RecyclerView rv = (RecyclerView) getView().findViewById(R.id.recycler_view);
        RecyclerViewAdapter2 adapter = new RecyclerViewAdapter2(context, lstCard);
        rv.setLayoutManager(new GridLayoutManager(context, 3));
        rv.setAdapter(adapter);
    }
}