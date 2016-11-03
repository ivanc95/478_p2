package project2;

public class Link {
	// Attributes
	private int NodeNumberA;
	private int NodeNumberB;
	private int Type;
	
	// Constructors
	Link() {
		setA(0);
		setB(0);
		setType(0);
	}
	Link(String input) {
		parseString(input);
	}
	
	// File Line to Link Object
	private void parseString(String input) {
		String[] data = input.split("\\|");
		this.setA(Integer.parseInt(data[0]));
		this.setB(Integer.parseInt(data[1]));
		this.setType(Integer.parseInt(data[2]));
	}
	public void printLink() {
		if(this.getType() == 0) { 
			System.out.println("Peer 1: \n\t" + this.getA() + "\nPeer 2: \n\t" + this.getB());
		}
		else {
			System.out.println("Provider: \n\t" + this.getA() + "\nCustomer: \n\t" + this.getB());
		}
	}
	
	// Getters and Setters
	public int getA() {
		return NodeNumberA;
	}
	public void setA(int nodeNumberA) {
		NodeNumberA = nodeNumberA;
	}
	public int getB() {
		return NodeNumberB;
	}
	public void setB(int nodeNumberB) {
		NodeNumberB = nodeNumberB;
	}
	public int getType() {
		return Type;
	}
	public void setType(int type) {
		Type = type;
	}	
}
