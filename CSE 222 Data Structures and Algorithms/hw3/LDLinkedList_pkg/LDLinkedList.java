package LDLinkedList_pkg;

import java.util.*;

/**
 *LDLinkedList is a custom implementation of a linked list, which extends AbstractList<E> and implements List<E> interfaces.
 *It stores data of generic type E in nodes and links the nodes together to form a list. Performs element removal with Lazy Deletion
 *Nodes that have been marked as deleted will be removed when there are two marked nodes.
 *@param <E> the type of element stored in the linked list.
 */
public class LDLinkedList<E> extends AbstractList<E> implements List<E> {
    private int size;
    private Node head;
    private int will_be_deleted_num = 0;


    /**
     * Creates a new node with the specified data element and initializes the next node to null and the isDeleted flag to false.
     *
     * @param element the data element to be stored in the node.
     */    
    private class Node {
        E data;
        Node next;
        boolean isDeleted;

        Node(E element) {
            this.data = element;
            this.next = null;
            this.isDeleted = false;
        }

        /**
         * Returns whether the node is marked as deleted.
         *
         * @return true if the node is marked as deleted, false otherwise.
         */
        public boolean getIsDeleted(){
            return isDeleted;
        }
    }

    /**
     * Creates an empty linked list with a head node that is null and a size of zero.
     */    
    public LDLinkedList() {
        this.head = null;
        this.size = 0;
    }

    /**
     * Returns the number of elements in the linked list.
     *
     * @return the number of elements in the linked list.
     */    
    @Override
    public int size() {
        return size;
    }


    /**
     * Appends the specified element to the end of the linked list.
     *
     * @param element the element to be appended to the end of the linked list.
     * @return true always.
     */    
    @Override
    public boolean add(E element) {
        Node newNode = new Node(element);
        if (head == null) {
            head = newNode;
        } else {
            Node current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
        }
        size++;
        return true;
    }

    /**
     * Returns the element at the specified position in the linked list.
     *
     * @param index the index of the element to be returned.
     * @return the element at the specified position in the linked list.
     * @throws IndexOutOfBoundsException if the index is out of range.
     */    
    @Override
    public E get(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException();
        }
        Node current = head;
        int i = 0;
        while (i < index) {
            current = current.next;
            i++;
        }
        return current.data;
    }

    /**
     * Removes the element at the specified position in the linked list.
     * If there are two nodes marked as deleted, they will be removed from the linked list.
     * If only one node is marked to be deleted, it is not physically removed.
     * @param index the index of the element to be removed.
     * @return the element that was removed from the linked list.
     * @throws IndexOutOfBoundsException if the index is out of range.
     */    
    @Override
    public E remove(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException();
        }
        Node current = head;
        int i = 0;
        while (i < index) {
            current = current.next;
            i++;
        }
        current.isDeleted = true;
        will_be_deleted_num++;
        if(will_be_deleted_num == 2){    
            removeMarkedNodes();
            will_be_deleted_num = 0;
        }
        return current.data;
    }

    /**
     * Removes items marked for deletion
     */
    private void removeMarkedNodes() {
        Node current = head;
        Node prev = null;
        while (current != null) {
            if (current.isDeleted) {

                if(current == head){
                    head = current.next;
                    size--;
                }
                else{
                    prev.next = current.next;
                    size--;
                }
            }
            prev = current;
            current = current.next;
        }
    }
}
