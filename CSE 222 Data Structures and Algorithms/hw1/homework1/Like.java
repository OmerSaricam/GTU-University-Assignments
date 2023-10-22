package homework1;


/**
 * The Like class represents a user's like on a post on a social media platform.
 * It extends the Interaction class and contains information about the account that
 * made the like.
 */
public class Like extends Interaction {
    
    /** the account that made the like */
    private Account[] account = new Account[1]; 

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
        this.account[0] = account_;
    }

    /**
     * Returns the account that made the like.
     * 
     * @return the account that made the like
     */
    public Account[] getAccount(){
        return account;
    }
}
