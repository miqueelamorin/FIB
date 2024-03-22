package junit.com;

public class BostonFactory implements PayStationFactory{
    public BostonFactory() {
    }

    public Receipt createReceipt(int parkTime) {
        return new BarCodeReceipt(parkTime);
    }

    public RateStrategy createRateStrategy() {
        return new ProgressiveRateStrategy();
    }
}
