package homework1;

/**

This class represents a post on a social media platform.
A post has an ID number, an account ID of the user who created it, contents, a number of likes, and a number of comments.
Users can like and comment on posts.
*/
public class Post {
    
    /** The ID number of this post*/
    private final int postId; 

    /** The account ID of the user who created this post.*/
    private final int accountId;

    /** The number of likes this post has received */
    private int like_number = 0;  

    /** An array of Like objects representing the users who have liked this post. */
    private Like[] likes = new Like[50];  

    /** The number of comments this post has received.*/
    private int comment_number = 0;

    /** An array of Comment objects representing the comments on this post.*/
    private Comment[] comments = new Comment[50];

    /** The contents of this post.*/
    private String contents;

    /**
     * Constructs a new Post object with the given ID number, account ID, and contents.
     * 
     * @param postId The ID number of this post.
     * @param accountId The account ID of the user who created this post.
     * @param contents The contents of this post.
     */
    public Post(final int postId, final int accountId, String contents){
        
        this.postId = postId;
        this.accountId = accountId;
        this.contents = contents;
    }

    /**
     * Returns the ID number of this post.
     * 
     * @return The ID number of this post.
     */
    public int getPostId(){ return postId; }

    /**
     * Returns the account ID of the user who created this post.
     * 
     * @return The account ID of the user who created this post.
     */   
    public int getAccountId(){ return accountId; }

    /**
     * Returns the number of likes this post has received.
     * 
     * @return The number of likes this post has received.
     */    
    public int getLike_number(){ return like_number; }

    /**
     * Returns an array of Like objects representing the users who have liked this post.
     * 
     * @return An array of Like objects representing the users who have liked this post.
     */
    public Like[] getLike(){ return likes; }

    /**
     * Returns the number of comments this post has received.
     * 
     * @return The number of comments this post has received.
     */
    public int getComment_number(){ return comment_number; }

    /**
     * Returns an array of Comment objects representing the comments on this post.
     * 
     * @return An array of Comment objects representing the comments on this post.
     */
    public Comment[] getComment(){ return comments; }

    /**
     * Returns the contents of this post.
     * 
     * @return The contents of this post.
     */    
    public String getContents(){ return contents; }
    
    //interactionId is given manually because static is forbidden
    /**
     * Adds a new like to this post with the given interaction ID, account ID, and Account object. 
     * interactionId is given manually because static is forbidden
     * 
     * @param interactionId The ID number of this like interaction.
     * @param accountIdd The account ID of the user who liked this post.
     * @param account_ The Account object representing the user who liked this post.
     */
    public void liking_process(final int interactionId, final int accountIdd, Account account_){

        Like like_ = new Like(interactionId,accountIdd,this.postId,account_,like_number);
        likes[like_number] = like_;
        like_number++;
    }

    /**

    Adds a comment to the post with the given interaction ID, using the specified account and content.
    Increments the comment number for this post.
    @param interactionId the ID of the post to add the comment to
    @param accountIdd the ID of the account that made the comment
    @param account_ the Account object representing the account that made the comment
    @param content_ the content of the comment
    */    
    public void commenting_process(final int interactionId, final int accountIdd, Account account_, String content_){

        Comment comment_ = new Comment(interactionId,accountIdd,this.postId,account_,content_);
        comments[comment_number] = comment_;
        comment_number++;
    }    
}
