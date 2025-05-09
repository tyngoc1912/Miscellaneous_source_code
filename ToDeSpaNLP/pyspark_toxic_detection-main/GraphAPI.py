import requests
from urllib import request
import json

user_access_token = ''
app_id = ''
app_secret = ''

# extend shortlive token
# get a long live user access token
# url = f'https://graph.facebook.com/oauth/access_token?grant_type=fb_exchange_token&client_id={app_id}&client_secret={app_secret}&fb_exchange_token={user_access_token}'
# access_token_response = request.urlopen(url)
# long_live_token = json.loads(access_token_response.read().decode("utf-8"))
# access_token = long_live_token['access_token']

page_id = ''
user_access_token = ''

# url = f'https://graph.facebook.com/334235118381548/accounts?access_token={user_access_token}'
     
# response = requests.get(url)

# page_access_token = json.loads(response.text)['data'][0]['access_token']

page_access_token = ''

class Graph(object):
    """
    This class facilitate interacting with Facebook Graph API version v11
    """
    def __init__(self, page_access_token, page_id):
        self.page_access_token = page_access_token
        self.page_id = page_id

    def get_page_name(self) -> str:
        """return page name of this page access token
        """
        url = f"https://graph.facebook.com/v11.0/me?access_token={self.page_access_token}"
        response = json.loads(requests.get(url).text)
        page_name = response['name']
        return page_name

    def post_story(self, message) -> str:
        """
        post a post to page with message
        """
        url = f"https://graph.facebook.com/me/feed?message={message}&access_token={self.page_access_token}"
        response = json.loads(requests.post(url, ).text)
        post_id = response['id']
        return post_id

    def get_all_post(self) -> dict:
        """
        get all post on the page and return a dict contains all posts
        """
        #fields=id,can_reply_privately,from,message,comments
        url = f"https://graph.facebook.com/me/feed/?&access_token={self.page_access_token}"
        response = json.loads(requests.get(url).text)
        return response
    
    def delete_post(self, post_id) -> bool:
        """
        delete a post has post_id.
        return True if successully delete, False otherwise
        """
        url = f'https://graph.facebook.com/{post_id}?access_token={self.page_access_token}'

        response = json.loads(requests.delete(url).text)
        return response['success']

    def pull_post_cmts(self, post_id) -> dict:
        """
        pull all cmts of a post has post_id
        """
        data = []
        url = f"https://graph.facebook.com/{post_id}/comments?limit=1000&filter=stream&access_token={self.page_access_token}"
        response = json.loads(requests.get(url).text)
        data.extend(response['data'])

        # if 'paging' in list(response.keys()):
        #     while 'next' in list(response['paging'].keys()) :
        #         response = json.loads(requests.get(response['paging']['next']).text)
        #         data.extend(response['data'])

        #     while 'after' in list(response.keys()):
        #         response = json.loads(requests.get(url + f"&after={response['paging']['after']}").text)
        #         data.extend(response['data'])

        return data

    def send_private_message(self,message, cmt_id ) -> bool:
        """
        send a private message to a facebook user who comment on a post
        return True if successully, otherwise False
        """
        url=f"https://graph.facebook.com/me/messages?recipient={{comment_id:'{cmt_id}'}}&message={{text:'{message}'}}&message_type=RESPONSE&access_token={page_access_token}"
        response = json.loads(requests.post(url).text)
        if 'message_id' in response.keys():
            return True
        return False
    
    def block_someone(self,user_id ):
        """
        block a facebook user from commenting on the page
        return True if successul otherwise False
        """
        url = f"https://graph.facebook.com/me/blocked?user={user_id}&access_token={self.page_access_token}"

        response = json.loads(requests.post(url).text)
        return True if ('user-id-to-block' in response.keys() and response['user-id-to-block'] == True) else False

    def delete_cmt_or_post(self, object_id):
        """
        delete a page post has post_id
        return True if successful
        """
        url = f'https://graph.facebook.com/v11.0/{object_id}?access_token={self.page_access_token}'

        response = json.loads(requests.delete(url).text)
    
        if 'success' in response.keys():
            if response['success']:
                return True
        return False

if __name__ == '__main__':
    pass