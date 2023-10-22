package LDLinkedList_pkg;


/**
 * The Like class represents a user's like on a post on a social media platform.
 * It extends the Interaction class and contains information about the account that
 * made the like.
 */
public class Like extends Interaction {
    
    /** the account that made the like */
    private Account account;  

    private boolean isDeleted;

    /**
     * Constructor for the Like class.
     * 
     * @param interactionId the ID of the interaction
     * @param accountId the ID of the account that made the like
     * @param postId the ID of the post that was liked
     * @param account_ the account that made the like
     * @param like_number the number of the like (not used in this implementation)
     */
    public Like(final int interactionId, final int accountId, final int postId, Account account_,final int like_number){
        super(interactionId, accountId, postId);
        account = account_;
    }

    /**
     * Returns the account that made the like.
     * 
     * @return the account that made the like
     */
    public Account getAccount(){
        return account;
    }


    /**
     * getter specifying whether to delete this comment
     * @return Returns true if the comment will be deleted, false if not
     */
    public boolean getIsDeleted(){
        return isDeleted;
    }

    /**
     * Set whether to delete the comment
     * @param a send true if you want to delete the comment, false if not
     */
    public void setIsDeleted(boolean a){
        isDeleted = a;
    }
}
