package project2;

import java.util.ArrayList;

public class Node {
	int ASnum;
	ArrayList<Link> isProviderIn = new ArrayList<Link>();
	ArrayList<Link> isCustomerIn = new ArrayList<Link>();
	ArrayList<Link> isPeerIn = new ArrayList<Link>();
	
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
	
	public int getDegree() {
		return isProviderIn.size() + isCustomerIn.size() + isPeerIn.size();
	}
	
	public void printNode() {
		System.out.println("Node #" + ASnum + " is Provider in " + isProviderIn.size() + " links, a customer in " + isCustomerIn.size() + " links and a peer in " + isPeerIn.size() + " links.");
	}
	
}