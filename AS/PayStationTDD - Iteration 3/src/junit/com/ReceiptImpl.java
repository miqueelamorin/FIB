package junit.com;

public class ReceiptImpl implements Receipt{
  private final int value;
  public ReceiptImpl( int value ) {
    this.value = value;
  }
  @Override
  public int value() {
    return value;
  }

}
