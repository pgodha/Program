import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 
 */

/**
 * @author pg027919
 *
 */
public class convertTwoDimensionalArrayIntoBinaryTree {
	
	public static void main(String args[]){
		
		int[][] arr = {
			{2, 4},
			{1, 2},
			{3, 6},
			{1, 3},
			{2, 5},
			{3, 7},
			{4, 8}
		};
		
		Map<Integer,List<Integer>> lookupMap= createMap(arr);
		
		System.out.println("hash map: "+lookupMap);
		
		int root = getRoot(lookupMap);
		
		System.out.println("Root: "+root);
		
		Node rt= new Node();
	    rt.val = root;
		
		createTree(rt, lookupMap);
		
		traverse(rt);
		
	}

	private static void traverse(Node current) {
		if( current != null){
			System.out.println(current.val+" ");
			traverse(current.leftChild);
			traverse(current.rightChild);		
		}
	}

	private static int getRoot(Map<Integer, List<Integer>> treeMap) {
		
		int root = -1;
		List<Integer> valList = new ArrayList<Integer>();
		for (int key : treeMap.keySet()){
			valList.addAll(treeMap.get(key));
		}
		

		for (int key : treeMap.keySet()){

			if(!valList.contains(key)) 
				root = key;
		}
		
		return root;
		
	}

	// create map to store child-parent relationship
	private static Map<Integer, List<Integer>> createMap(int[][] arr) {
		Map<Integer, List<Integer>> treeMap = new HashMap<Integer,List<Integer>>();
		List<Integer> tempList;
		for( int i = 0; i < arr.length; i++) {
			
			if (treeMap.containsKey(arr[i][0])){
				tempList = treeMap.get(arr[i][0]);
			}
			else
				tempList = new ArrayList<Integer>();
			tempList.add(arr[i][1]);
			treeMap.put(arr[i][0], tempList);
		}
			
		return treeMap;
	}


	// After getting root create tree using hash map
	private static void createTree(Node node, Map<Integer, List<Integer>> treeMap) {
		
		List<Integer> childList = treeMap.get(node.val);
	    if(childList == null)
	    	return;
	    
	    System.out.println("childList: "+childList);
	    
    	Node nodeLeft = new Node();
    	nodeLeft.val = childList.get(0);
    	node.leftChild = nodeLeft;
    	
    	Node nodeRight = new Node();
    	if(childList.size() == 2){
    	
    	nodeRight.val = childList.get(1);
    	node.rightChild = nodeRight;
    	}
    	createTree(nodeLeft, treeMap);
    	createTree(nodeRight, treeMap);
	}
}

class Node {
	int val;
	Node leftChild;
	Node rightChild;
}
