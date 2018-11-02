package readerwirter;

import java.util.concurrent.Semaphore;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ReaderWirter {
   static int rc=0;
  static Semaphore S= new Semaphore(1);
    static Semaphore wrt =new Semaphore(1);
static class Reader implements Runnable{

        @Override
        public void run() {
            try {
                S.acquire();
                rc++;
                if(rc==1)
                    wrt.acquire();
                S.release();
                System.out.println(Thread.currentThread().getName()+" is reading");
                Thread.sleep(5000);
                System.out.println("reading finished!!!!");
                S.acquire();
                rc--;
                if(rc==0)
                    wrt.release();
                S.release();
            } catch (InterruptedException ex) {
                Logger.getLogger(ReaderWirter.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
}
static class Writer implements Runnable {

        @Override
        public void run() {
            try {
                wrt.acquire();
                System.out.println(Thread.currentThread().getName()+" is writing!!");
                Thread.sleep(5000);
                System.out.println("writer finished!!");
                wrt.release();
            } catch (Exception e) {
            }
        }
    }

    public static void main(String[] args) {
        while(true){
       Reader r = new Reader();
       Writer write = new Writer();
       Thread t1= new Thread(r);
       t1.setName("thread 1");
       Thread t2= new Thread(r);
       t2.setName("thread 2");
       Thread t3= new Thread(r);
       t3.setName("thread 3");
       t1.start();
       t2.start();
       t3.start();
       Thread t4 = new Thread(write);
       t4.setName("thread 4");
       t4.start();
       Thread t5 = new Thread(write);
       t5.setName("thread 5");
       t5.start();
        } 
        }
    
}