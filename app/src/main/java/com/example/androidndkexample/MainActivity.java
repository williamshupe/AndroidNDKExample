package com.example.androidndkexample;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import java.util.Random;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private TextView mShotStat;
    private TextView mGoalsStat;
    private TextView mAssistsStat;
    private TextView mPlayerStatus;

    private Player mPlayer;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mPlayer = new Player();

        mShotStat = (TextView)findViewById(R.id.shots_stat);
        mGoalsStat = (TextView)findViewById(R.id.goals_stat);
        mAssistsStat = (TextView)findViewById(R.id.assists_stat);
        mPlayerStatus = (TextView)findViewById(R.id.player_status);

        findViewById(R.id.pass_button).setOnClickListener(this);
        findViewById(R.id.shoot_button).setOnClickListener(this);

        updateStats();
    }

    private void updateStats(){
        mShotStat.setText(String.valueOf(mPlayer.getShots()));
        mGoalsStat.setText(String.valueOf(mPlayer.getGoals()));
        mAssistsStat.setText(String.valueOf(mPlayer.getAssists()));
    }

    private void updatePlayerStatusText(String status){
        mPlayerStatus.setText(status);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.pass_button:
                String passResult = mPlayer.pass();
                updateStats();
                updatePlayerStatusText(passResult);
                break;
            case R.id.shoot_button:
                Random r = new Random();
                int power = r.nextInt(10);
                String shotResult = "Shot with power " + power + ": " + mPlayer.shoot(power);
                updateStats();
                updatePlayerStatusText(shotResult);
                break;
        }
    }
}
