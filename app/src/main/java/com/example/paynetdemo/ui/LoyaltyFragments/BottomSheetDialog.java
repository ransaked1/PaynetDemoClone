package com.example.paynetdemo.ui.LoyaltyFragments;

import android.content.Context;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;

import com.example.paynetdemo.R;
import com.google.android.material.bottomsheet.BottomSheetDialogFragment;
import com.example.paynetdemo.ui.MainFragments.LoyaltyFragment;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

public class BottomSheetDialog extends BottomSheetDialogFragment {

    private BottomSheetListener mListener;
    public  String originalText;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.bottom_sheet,container,false);

        Button button_cancel = v.findViewById(R.id.cancel_btn);

        button_cancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                mListener.onButtonClicked(originalText);
                dismiss();
            }
        });

        return v;
    }

    public interface BottomSheetListener{
        void onButtonClicked(String text);
    }

    public void setOriginalText(String originalText) {
        this.originalText = originalText;
    }

    @Override
    public void onAttach(@NonNull Context context) {
        super.onAttach(context);

        try {
            mListener = (BottomSheetListener) context;
        } catch (ClassCastException e) {
            throw new ClassCastException(context.toString() + "must implement BottomSheetListener");
        }
    }
}
