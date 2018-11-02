import java.util.Scanner;
public class NewClass {
    static int s=1,E=10,F=0;
    static int wait(int s)
    {
        return --s;
    }
    static int signal(int s)
    {
        return ++s;
    }
    static void producer()
    {
        s=wait(s);
        E=wait(E);
        F=signal(F);
        System.out.println("Producer");
        s=signal(s);
    }
    static void consumer()
    {
        s=wait(s);
        E=signal(E);
        F=wait(F);
        System.out.println("Consumer");
        s=signal(s);
    }
    public static void main(String[] args) { 
        int ch;
        while(true)
        {
            System.out.println("1 for producer.");
            System.out.println("2 for consumer.");
            System.out.println("3 for exit.");
            Scanner s1= new Scanner(System.in);
            ch = s1.nextInt();
            switch(ch)
            {
                case 1:
                    if(s==1 && E!=0)
                    producer();
                    else
                        System.out.println("Producer waiting");
                    break;
                    
                case 2:
                    if(s==1 && F!=0)
                    consumer();
                    else
                        System.out.println("Consumer waiting");
                    break;
                    
                case 3:
                    System.exit(0);
            }
        }        
    }
}
    