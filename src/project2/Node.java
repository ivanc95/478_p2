package project2;

import java.util.ArrayList;

public class Node {
	// Attributes
	private int ASnum;
	private ArrayList<Link> isProviderIn = new ArrayList<Link>();
	private ArrayList<Link> isCustomerIn = new ArrayList<Link>();
	private ArrayList<Link> isPeerIn = new ArrayList<Link>();
	
	// Constructors
	Node(int id, Link first) {
		if(first.getType() == -1) {
			if(first.getA() == id) {
				this.isProviderIn.add(first);
			}
			else {
				this.isCustomerIn.add(first);
			}
		}
		else {
			this.isPeerIn.add(first);
		}
		this.ASnum = id;
	}
	public void addLink(Link toAdd) {
		if(toAdd.getType() == -1) {
			if(toAdd.getA() == this.ASnum) {
				this.isProviderIn.add(toAdd);
			}
			else {
				this.isCustomerIn.add(toAdd);
			}
		}
		else {
			this.isPeerIn.add(toAdd);
		}
	}
	
	// Structure output methods
	public int getDegree() {
		return isProviderIn.size() + isCustomerIn.size() + isPeerIn.size();
	}
	
	public void printNode() {
		System.out.println("Node #" + ASnum + ":\n\tis a provider in " + isProviderIn.size() + " links\n\tis a customer in " + isCustomerIn.size() + " links\n\tis a peer in " + isPeerIn.size() + " links.");
	}
	
}