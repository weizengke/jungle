#ifndef _COMMAND_TYPE_H_
#define _COMMAND_TYPE_H_

/* BEGIN: Added by weizengke, 2013/10/27  for debug switch*/

#ifndef INVALID_SOCKET
#define INVALID_SOCKET	(ULONG)(~0)
#endif

#ifndef SOCKET_ERROR
#define SOCKET_ERROR	(-1)
#endif



// command match type
enum CMD_MATCH_STATUS {
	CMD_NO_MATCH,
	CMD_FULL_MATCH,
	CMD_PART_MATCH,
	CMD_LIST_MATCH,
	CMD_ERR_AMBIGOUS,
	CMD_ERR_ARGU,
};



enum CMD_ELEM_ID_EM {
	CMD_ELEM_ID_NONE = -1,
	CMD_ELEM_ID_CR,
	CMD_ELEM_ID_UNDO,
	CMD_ELEM_ID_ENABLE,
	CMD_ELEM_ID_DISABLE,
	CMD_ELEM_ID_DISPLAY,
	CMD_ELEM_ID_EVENT,
	CMD_ELEM_ID_DEBUG,
	CMD_ELEM_ID_TERMINAL,
	CMD_ELEM_ID_DEBUGING,
	CMD_ELEM_ID_ON,
	CMD_ELEM_ID_OFF,
	CMD_ELEM_ID_VERSION,

	CMD_ELEM_ID_COMMON,
	CMD_ELEM_ID_CMD,

	CMD_ELEM_ID_SYSNAME,
	CMD_ELEM_ID_CLOCK,
	CMD_ELEM_ID_COMPUTER,

	CMD_ELEM_ID_STRING1TO24,
	CMD_ELEM_ID_STRING1TO32,
	CMD_ELEM_ID_STRING1TO256,
	CMD_ELEM_ID_STRING1TO65535,
	CMD_ELEM_ID_INTEGER1TO24,
	CMD_ELEM_ID_INTEGER1TO65535,

	CMD_ELEM_ID_RETURN,
	CMD_ELEM_ID_QUIT,
	CMD_ELEM_ID_SYSTEM_VIEW,
	CMD_ELEM_ID_DAIGNOSE_VIEW,
	CMD_ELEM_ID_AAA,
	
    CMD_ELEM_ID_COMMAND_TREE,
    CMD_ELEM_ID_CURRENT_CFG,

	CMD_ELEM_ID_HISTTORY,

	CMD_ELEM_ID_VJUDGE,

	CMD_ELEM_ID_DEBUG_ERROR,
	CMD_ELEM_ID_DEBUG_FUNC,
	CMD_ELEM_ID_DEBUG_INFO,
	CMD_ELEM_ID_DEBUG_MSG,
	CMD_ELEM_ID_DEBUG_FSM,
	CMD_ELEM_ID_DEBUG_ALL,

    CMD_ELEM_ID_LOGIN,
    CMD_ELEM_ID_HDUJUDGE,
	CMD_ELEM_ID_GUETJUDGE,
	CMD_ELEM_ID_REMOTE_JUDGE,
    CMD_ELEM_ID_USERNAME,
    CMD_ELEM_ID_PASSWORD,

	CMD_ELEM_ID_STATUS,
    CMD_ELEM_ID_JUDGE,
    CMD_ELEM_ID_SOLUTION,
    CMD_ELEM_ID_PROBLEM,
    CMD_ELEM_ID_SET,
    CMD_ELEM_ID_CONFIG,
    CMD_ELEM_ID_REBOOT,
    CMD_ELEM_ID_BRIEF,
    CMD_ELEM_ID_IP,
    CMD_ELEM_ID_PORT,

	CMD_ELEM_ID_MODE,
	CMD_ELEM_ID_ACM,
	CMD_ELEM_ID_OI,

	CMD_ELEM_ID_ROLE,
	CMD_ELEM_ID_MASTER,
	CMD_ELEM_ID_AGENT,

	CMD_ELEM_ID_NDP,
	CMD_ELEM_ID_SERVER,
	CMD_ELEM_ID_CLIENT,
	CMD_ELEM_ID_BIND,
	CMD_ELEM_ID_NEIGHBOR,
	CMD_ELEM_ID_AUTO_DETECT,
	CMD_ELEM_ID_INTERVAL,
	CMD_ELEM_ID_DATAPATH,
	CMD_ELEM_ID_MYSQL,
	CMD_ELEM_ID_URL,
	CMD_ELEM_ID_TABLE,
	CMD_ELEM_ID_SAVE,
	CMD_ELEM_ID_SAVE_CFG,
	CMD_ELEM_ID_TELNET,
	CMD_ELEM_ID_SYSTEM,
	CMD_ELEM_ID_USERS,
	CMD_ELEM_ID_AUTHENTICATION_MODE,
	CMD_ELEM_ID_MODE_NONE,

	CMD_ELEM_ID_LOCAL_USER,
	CMD_ELEM_ID_SECURITY,
	CMD_ELEM_ID_JUDGE_MGR,
	CMD_ELEM_ID_VJUDGE_MGR,
	CMD_ELEM_ID_THIS,
	CMD_ELEM_ID_INC_DEFAULT,
	CMD_ELEM_ID_MAX,

};


enum CMD_KEY_CODE_EM {
	CMD_KEY_CODE_NONE = -1,
		CMD_KEY_CODE_FILTER = 0,
		CMD_KEY_CODE_TAB,  // CMD_KEY_CODE_TAB
		CMD_KEY_CODE_ENTER,
		CMD_KEY_CODE_QUEST,
		CMD_KEY_CODE_UP,
		CMD_KEY_CODE_DOWN,
		CMD_KEY_CODE_LEFT,
		CMD_KEY_CODE_RIGHT,
		CMD_KEY_CODE_DELETE,	 /* delete�� */
		CMD_KEY_CODE_BACKSPACE,  /* �˸�� */
	    CMD_KEY_CODE_DEL_LASTWORD,    /* 10 */

		CMD_KEY_CODE_NOTCARE,   /* 11 */

		CMD_KEY_CODE_MAX
};

struct cmd_elem_st {
	ULONG mid;
	ULONG view_id;
	ULONG para_num;
	CMD_VECTOR_S *para_vec;
};

typedef struct para_desc {
	CMD_ELEM_TYPE_E  elem_tpye;
	ULONG  elem_id;  /* ������Ԫ��id */
	CHAR *para;    /* ������Ԫ���� */
	CHAR *desc;    /* �����ְ�����Ϣ */
}CMD_ELEM_S;

#define CMD_VIEW_SONS_NUM 100

typedef struct cmd_view_node {
	ULONG  view_id;
	CHAR view_name[CMD_MAX_VIEW_SIZE];
    CHAR view_ais_name[CMD_MAX_VIEW_SIZE];

	struct cmd_view_node *pParent;
	struct cmd_view_node **ppSons;
	ULONG view_son_num;

}view_node_st;


typedef struct CMD_RUN_Ntf_Node
{
	ULONG  mId;
	ULONG  (*pfCallBackFunc)(VOID *pRcvMsg); /* �ص������������ڴ棬�ɵ������ͷ� */

	struct CMD_RUN_Ntf_Node *pNext;
};

typedef struct tagCMD_RUNMSG_ELEM_S
{
	ULONG cmd_elemId;
	CHAR cmd_param[128];
}CMD_RUNMSG_ELEM_S;

typedef struct tagCMD_RUNMSG_S
{
	ULONG vtyId;
	ULONG argc;
	CMD_RUNMSG_ELEM_S *argv;
}CMD_RUNMSG_S;


typedef struct key_handler {
	ULONG key_value;
	VOID (*key_func)(struct cmd_vty *);
} key_handler_t;

#endif


