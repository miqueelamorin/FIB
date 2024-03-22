package junit.com;

public interface PayStationFactory {
    public Receipt createReceipt(int parkTime);

    public RateStrategy createRateStrategy();
}
