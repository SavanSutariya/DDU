class ThreadDemo1 extends Thread {
    ThreadDemo1(String name) {
        super(name);
    }
    public void run() {
        System.out.println("Thread " + getName() + " started");
        for (int i = 1; i <= 5; i++) {
            System.out.println("Thread " + getName() + " : " + i);
            try {
                sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("Thread " + getName() + " ended");
    }
}

class ThreadDemo2 extends Thread {
    ThreadDemo2(String name) {
        super(name);
    }
    public void run() {
        System.out.println("Thread " + getName() + " started");
        for (int i = 1; i <= 6; i++) {
            System.out.println("Thread " + getName() + " : " + i);
            try {
                sleep(2000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("Thread " + getName() + " ended");
    }
}

class ThreadDemo3 extends Thread {
    ThreadDemo3(String name) {
        super(name);
    }
    public void run() {
        System.out.println("Thread " + getName() + " started");
        for (int i = 1; i <= 7; i++) {
            System.out.println("Thread " + getName() + " : " + i);
            try {
                sleep(3000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("Thread " + getName() + " ended");
    }
}

public class p1 {
    public static void main(String[] args) {
        ThreadDemo1 t1 = new ThreadDemo1("Thread 1");
        ThreadDemo2 t2 = new ThreadDemo2("Thread 2");
        ThreadDemo3 t3 = new ThreadDemo3("Thread 3");
        System.out.println("Thread 1 is alive: " + t1.isAlive());
        System.out.println("Thread 2 is alive: " + t2.isAlive());
        System.out.println("Thread 3 is alive: " + t3.isAlive());
        System.out.println("Main thread is alive: " + Thread.currentThread().isAlive());
        t1.start();
        t2.start();
        t3.start();
        System.out.println("Thread 1 is alive: " + t1.isAlive());
        System.out.println("Thread 2 is alive: " + t2.isAlive());
        System.out.println("Thread 3 is alive: " + t3.isAlive());
        System.out.println("Main thread is alive: " + Thread.currentThread().isAlive());
        System.out.println("Main thread ended");
    }
}