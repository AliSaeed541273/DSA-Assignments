//THREAD ASSIGNMENT 

import com.sun.jdi.ThreadReference;

public class MyThread extends Thread{
    private boolean isEven;
    public MyThread(String name,boolean isEven){
        super(name);
        this.isEven = isEven;
    }

    public boolean isEven() {
        return isEven;
    }
    @Override
    public void run(){
        if(isEven){
            for(int i=0;i<100;i+=2){
                System.out.println(i);
            }
        }else{
            for(int i=1;i<100;i+=2){
                System.out.println(i);
            }
        }
    }
}
public class Main {
    public static void main(String[] args) {

//        MyThread mt1 = new MyThread("Even",true);
//        MyThread mt2 = new MyThread("Odd",false);
//        mt1.start();
//        mt2.start();
       MyThread2 mt2 = new MyThread2(true);
        MyThread2 mt3 = new MyThread2(false);
        Thread t1 = new Thread(mt2);
        Thread t2 = new Thread(mt3);
        t1.start();
        t2.start();
    }
}
