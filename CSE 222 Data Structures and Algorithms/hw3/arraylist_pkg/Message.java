package arraylist_pkg;

import java.util.ArrayList;


/**

The Message class represents a message sent between two user accounts.
It includes the message ID, sender ID, receiver ID, sender account, receiver account, and message content.
*/
public class Message {
    
    
    /** The ID of the message.*/
    private int messageIdd;

    /** The ID of the sender user account.*/
    private int senderId;

    /** The sender account of the user who sent the message. */
    private Account senderAcc;


    /** The ID of the receiver user account. */
    private int receiveId;

    /** The receiver account of the user who received the message. */
    private Account receiverAcc;

    /** The content of the message. */
    private String content;

    /**
     * Constructs a Message object with the given message ID, sender ID, sender account, receiver ID, receiver account, and message content.
     *
     * @param messageIdd the ID of the message.
     * @param senderId the ID of the sender user account.
     * @param senderAcc the sender account of the user who sent the message.
     * @param receiveId the ID of the receiver user account.
     * @param receiverAcc the receiver account of the user who received the message.
     * @param content the content of the message.
     */
    public Message(final int messageIdd,final int senderId, Account senderAcc, final int receiveId, Account receiverAcc, final String content){
        this.messageIdd = messageIdd;
        this.senderId = senderId;
        this.senderAcc = senderAcc;

        this.receiveId = senderId;
        this.receiverAcc = receiverAcc;
        this.content = content;
    }

    /**
     * Returns the ID of this Message object.
     *
     * @return the ID of this Message object.
     */
    public int getMessageIdd(){ return messageIdd; }

    /**
     * Returns the ID of the sender user account of this Message object.
     *
     * @return the ID of the sender user account of this Message object.
     */
    public int getSenderId(){ return senderId; }

    /**
     * Returns the sender account of the user who sent the message.
     *
     * @return the sender account of the user who sent the message.
     */
    public Account getSenderAcc(){ return senderAcc; }

    /**
     * Returns the ID of the receiver user account of this Message object.
     *
     * @return the ID of the receiver user account of this Message object.
     */
    public int getReceiveId(){ return receiveId; }

    /**
     * Returns the receiver account of the user who received the message.
     *
     * @return the receiver account of the user who received the message.
     */
    public Account getReceiverAcc(){ return receiverAcc; }

    /**
     * Returns the content of this Message object.
     *
     * @return the content of this Message object.
     */
    public String getContent(){ return content; }





}
