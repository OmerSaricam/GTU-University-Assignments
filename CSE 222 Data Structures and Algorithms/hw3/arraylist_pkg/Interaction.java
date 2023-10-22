package arraylist_pkg;


import java.util.ArrayList;

/**

The Interaction class represents a user interaction with a post.
It includes the interaction ID, account ID, and post ID.
*/
public class Interaction {
    
    /**  The interaction ID of the user interaction. */
    private int interactionId;

    /** The account ID of the user who interacted with the post. */
    private int accountId;

    /** The post ID of the post that the user interacted with. */
    private int postId;

    /**
     * Constructs an Interaction object with the given interaction ID, account ID, and post ID.
     *
     * @param interactionId the ID of the user interaction.
     * @param accountId the ID of the user account.
     * @param postId the ID of the post.
     */
    public Interaction(final int interactionId, final int accountId, final int postId){
        this.interactionId = interactionId;
        this.accountId = accountId;
        this.postId = postId;
    }

    /**
     * Returns the interaction ID of this Interaction object.
     *
     * @return the interaction ID of this Interaction object.
     */
    public int getInteractionId(){ return interactionId; }

    /**
     * Returns the account ID of the user who interacted with the post.
     *
     * @return the account ID of the user who interacted with the post.
     */
    public int getAccountId(){ return accountId; }

    /**
     * Returns the post ID of the post that the user interacted with.
     *
     * @return the post ID of the post that the user interacted with.
     */
    public int getPostId(){ return postId; }
}
