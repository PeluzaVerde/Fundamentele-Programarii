from repo import Repository
import random

from repo import Repository
class servErr(Exception):
    pass
class service:
    def __init__(self, repo):
        self._repo = repo

    def add_question(self, id,text,choica,choicb,choicc,corr,diff):
        """adds a question to the masterfile"""
        if self.checkvalid(id,text,choica,choicb,choicc,corr,diff) is True:
            self._repo.add_question(id,text,choica,choicb,choicc,corr,diff)

    def checkvalid(self, id,text,choica,choicb,choicc,corr,diff):
        """
        checks id
        """
        if self.uniqueid(id) == False:
            raise servErr("not unqiue id")
        else:
            return True


    def uniqueid(self,id):
        """still checks id"""
        for i in self._repo.get_all_questions():
            if int(i[0]) == int(id):
                return False
        return True

    def create_quiz(self,diff,noq,file):
        """create quiz"""
        filename= str(file)
        allq =self._repo.get_all_questions()
        k=0
        list_of_q=list()
        for i in allq:
            tokens = i.strip().split(";")
            if str(tokens[6]) == str(diff):
                k+=1
                list_of_q.append(i)
        if int(k) < int(noq)//2:
            raise servErr("not enough questions of dificulty")
        with open(filename, "w") as s:
            question = list_of_q
            cont = 0
            for sentence in question:
                if int(cont) != int(noq):
                    cont+=1
                    s.write(sentence.strip() + '\n')
            s.close()

            pass


    # def choose_a_sentence(self):
    #     """
    #     used to choose a sentence randomly from the file.
    #     :return:
    #     """
    #     upper_limit = len(self._repo)-1
    #     lower_limit = 0
    #     choice = random.randint(lower_limit, upper_limit)
    #     return self._repo.get_sentence(choice)



