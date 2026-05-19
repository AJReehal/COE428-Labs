/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package coe528project;

/**
 *
 * @author ajreehal
 */
public class Customer extends User {
    private int points;
    private State state;
   
    public Customer (String username, String password){
        super (username, password);
        points = 0;
        state = new SilverState();
    }
   
    public int getPoints(){
        return points;
    }
   
    public void setPoints(int points){
        this.points = points;
    }
   
    public State getState(){
        return state;
    }
   
    public void setState(State state){
        this.state = state;
    }
   
    public void buy(double totalCost){
        state.buy(this, totalCost);
    }
   
    public double redeem(double totalCost){
        return state.redeem(this,totalCost);
    }
   
    public String getStatus(){
        return state.getStatus();
    }
   
}