#ifndef TREE_H
#define TREE_H
#include"Gridstruct.h"
#include"IJKGrid.h"
#include<queue>
namespace UMSM
{
	//�������ڵ���
	struct TreeNode
	{
		// �ڵ�����;
		CPGNode NodeData;
		int NumberChild;
		TreeNode **childNotes;
		// ���ӻ�����;
		bool * Cellarray;
		TreeNode(){	}; //�ڵ���
		TreeNode(const  int _nodenum, const CPGNode _nodedata)
		{
			NumberChild = _nodenum;
			NodeData = _nodedata;
			Cellarray = new bool[7];
			memset(Cellarray, false, sizeof(bool)* 7);
			if (NumberChild > 0)
			{
				childNotes = new TreeNode*[_nodenum];
			}
		};
	};
	class MyTree
	{
	public:
		TreeNode *root;		
		void Initlization(intArray TopLayers, intArray BottomLayers, NodeDatas nodeDatas, StrucGrid SGridData);
		int depth(TreeNode * &node);
		bool flag = false;
		ZoneData GetZoneData(int Depth);
		vector<ZoneData> GetZoneData(int Depth, PhaseMap Layers);		
		MyTree();
		~MyTree();
	private:			
		queue<TreeNode *> Treeque;
		void Merge(int TopLayer, int BottomLayer, StrucGrid SGridData, nodeData NoteData, int NX, int NY, CPGNode &node);
		void preOrder(int level, int depth, TreeNode *note);
		void createTree(TreeNode * &node, intArray TopLayers, intArray BottomLayers, NodeDatas nodeDatas, StrucGrid SGridData);
	};
};
#endif;