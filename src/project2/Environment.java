package project2;

import java.io.*;
import java.util.*;

public class Environment {
	public static void main(String[] args) {
		ArrayList<Link> links = new ArrayList<Link>();
		HashMap<Integer, Node> nodes = new HashMap<Integer, Node>();
		FileInputStream in = null;
		BufferedReader r = null;
		Link currentLink = null;
		String currentLine = "";
		int count = 1;
		try {
			in = new FileInputStream("./input2.txt");
			r = new BufferedReader(new InputStreamReader(in));
			currentLine = r.readLine();
			do {
				if(currentLine.charAt(0) != '#') {
					links.add(new Link(currentLine));
					currentLink = links.get(links.size()-1);
					if(nodes.get(currentLink.getA()) == null) {
						nodes.put(currentLink.getA(), new Node(currentLink.getA(), currentLink));
					}
					else {
						nodes.get(currentLink.getA()).addLink(currentLink);
					}
					if(nodes.get(currentLink.getB()) == null) {
						nodes.put(currentLink.getB(), new Node(currentLink.getB(), currentLink));
					}
					else {
						nodes.get(currentLink.getB()).addLink(currentLink);
					}
				}
				currentLine = r.readLine();
				count++;
			} while(currentLine != null);
			r.close();
			in.close();
		}
		catch (FileNotFoundException e) {
			System.out.println("The input file was not found! Make sure input2.txt is placed in the project directory!");
		}
		catch (IOException e)  {
			System.out.println("There was an error while parsing the file!");
		}
		catch (NumberFormatException e) {
			System.out.println("A NumberFormatException error occured while parsing a Link at " + count);
		}
		catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("An ArrayIndexOutOfBoundsException error occured while parsing a Link at " + count);
		}
		finally {
		    System.out.println("Link objects created: " + links.size());
		    System.out.println("Node objects created: " + nodes.size());
			nodes.get(3).printNode();
			histogramPls(nodes);
		}
	}
	
	private static void histogramPls(HashMap<Integer, Node> nodes) {
		Set<Integer> setk = nodes.keySet();
		int arr[] = {0,0,0,0,0,0};
		int curr = 0;
		for(int i : setk ) {
		    curr = nodes.get(i).getDegree();
		    if(curr == 1) {
		    	arr[0]++;
		    }
		    else if(curr > 1 && curr <= 5) {
		    	arr[1]++;
		    }
		    else if(curr > 5 && curr <= 100) {
		    	arr[2]++;
		    }
		    else if(curr > 100 && curr <= 200) {
		    	arr[3]++;
		    }
		    else if(curr > 200 && curr <= 1000) {
		    	arr[4]++;
		    }
		    else {
		    	arr[5]++;
		    }
		}
		System.out.println(arr[0] + ", " + arr[1] + ", " + arr[2] + ", " + arr[3] + ", " + arr[4] + ", " + arr[5]);
	}
}