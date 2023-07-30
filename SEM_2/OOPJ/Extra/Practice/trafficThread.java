public class trafficThread implements Runnable {
    private String currentLight;

    public trafficThread() {
        this.currentLight = "Red";
    }

    @Override
    public void run() {
        try {
            while (true) {
                switchLights();
                Thread.sleep(10000); // Sleep for 10 seconds
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    private synchronized void switchLights() {
        if (currentLight.equals("Red")) {
            currentLight = "Green";
        } else if (currentLight.equals("Green")) {
            currentLight = "Yellow";
        } else if (currentLight.equals("Yellow")) {
            currentLight = "Red";
        }
        System.out.println("Traffic light is now " + currentLight);
    }

    public static void main(String[] args) {
        trafficThread trafficThread = new trafficThread();
        Thread trafficThreadThread = new Thread(trafficThread);
        trafficThreadThread.start();
    }
}
