package com.example.androidndkexample;

public class Player {

    static {
        System.loadLibrary("ndk-example-jni");
    }

    private int goals;
    private int shots;
    private int assists;

    public Player(){
        goals = shots = assists = 0;
    }

    public native String shoot(int power);
    public native String pass();

    public int getAssists() {
        return assists;
    }

    public void setAssists(int assists) {
        this.assists = assists;
    }

    public int getShots() {
        return shots;
    }

    public void setShots(int shots) {
        this.shots = shots;
    }

    public int getGoals() {
        return goals;
    }

    public void setGoals(int goals) {
        this.goals = goals;
    }
}
