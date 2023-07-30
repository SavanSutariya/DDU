class t1 extends Thread{
    public void run(){
        int i=5;
        while(i>0){
            System.out.println("Thread 1 : "+i);
            i--;
        }
    }
}
class t2 extends Thread{
    public void run(){
        int i=5;
        while(i>0){
            System.out.println("Thread 2 : "+i);
            i--;
        }
    }
}
class multiThread{
    public static void main(String []args){
        t1 t = new t1();
        t2 t2 = new t2();
        t.start();
        t2.start();

    }
}