package LDLinkedList_pkg;


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

    /** An LDLinkedList of Like objects representing the users who have liked this post. */
    private LDLinkedList<Like> likes = new LDLinkedList<Like>();

    /** The number of comments this post has received.*/
    private int comment_number = 0;

    /** An array of Comment objects representing the comments on this post.*/
    private LDLinkedList<Comment> comments = new LDLinkedList<Comment>();

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
     * Returns an LDLinkedList of Like objects representing the users who have liked this post.
     * 
     * @return An LDLinkedList of Like objects representing the users who have liked this post.
     */
    public LDLinkedList<Like> getLike(){ return likes; }

    /**
     * Returns the number of comments this post has received.
     * 
     * @return The number of comments this post has received.
     */
    public int getComment_number(){ return comment_number; }

    /**
     * Returns an LDLinkedList of Comment objects representing the comments on this post.
     * 
     * @return An LDLinkedList of Comment objects representing the comments on this post.
     */
    public LDLinkedList<Comment> getComment(){ return comments; }

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
        likes.add(like_);
        like_number++;
    }

    /**
     * Unlike to this post with the given account. 
     * 
     * @param account_ The account ID of the user who liked this post.
     */
    public void unliking_process(Account account_){  

        for(int i=0 ; i< like_number; i++){

            if(likes.get(i).getAccountId() == account_.getAccountId() ){
                likes.remove(i);
                like_number--;
                likes.get(i).setIsDeleted(true);
                account_.addActions("You unliked the post of the account with" + accountId + " ID. Post ID: "+ postId + ". Post content: " + contents);
                return;
            }
        }

        System.out.printf("\nYou did not like this post. You must be like the post before you can unlike the post ");
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
        comments.add(comment_);
        comment_number++;
    }

   /**
    * Delete a comment in the post 
    * Decrements the comment number for this post.
    *@param account_ the account that made the uncomment process.
    *@param which_comment Information on which comment will be deleted
    */    
    public void uncommenting_process(Account account_,final int which_comment){
        
        int count = 1;
        for(int i=0 ; i< comment_number; i++){

            if(comments.get(i).getAccountId() == account_.getAccountId() ){

                if(count == which_comment){
                   comments.remove(i);
                   comment_number--;
                   comments.get(i).setIsDeleted(true);
                   account_.addActions("You uncommented the post of the account with" + accountId + " ID. Post ID: "+ postId + ". Post content: " + contents + ". Your deleted comment: " + comments.get(i).getContent());
                   return;
                }

                else count++;

            }
        }

        System.out.printf("\nYou did not comment this post. You must be comment the post before you can uncomment the post ");
    
    }    
}
