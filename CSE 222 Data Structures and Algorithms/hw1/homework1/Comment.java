package homework1;


/**
The Comment class extends Interaction and represents a comment made by an Account on a Post.
It contains the content of the comment and the Account who made the comment.
*/
public class Comment extends Interaction {
    
    /**
     * The content of the comment.
     */    
    private String content;

    /**
     * The Account who made the comment.
     */
    private Account[] account = new Account[1]; //yorum atan kişi


    /**
     * Constructor for the Comment class.
     * @param interactionId The ID of the Interaction.
     * @param accountId The ID of the Account who made the comment.
     * @param postId The ID of the Post that the comment was made on.
     * @param account_ The Account who made the comment.
     * @param content The content of the comment.
     */
    public Comment(final int interactionId, final int accountId, final int postId,Account account_, String content){

        super(interactionId, accountId, postId);
        this.content = content;
        this.account[0] = account_;  // comment number gereksiz
    }
        
    
    /**
     * Getter for the content of the comment.
     * @return The content of the comment.
     */    
    public String getContent(){ return content; }

    /**
     * Getter for the Account who made the comment.
     * @return The Account who made the comment.
     */    
    public Account[] getAccount(){
        return account;
    }
}
