package LDLinkedList_pkg;


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
    private Account account;


    private boolean isDeleted;



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
        account = account_;
        this.isDeleted = false;
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
