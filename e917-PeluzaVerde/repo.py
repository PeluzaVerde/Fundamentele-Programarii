
class RepoErr(Exception):
    pass


class Repository:
    def __init__(self, file_name):
        self._quiz = list()
        self._file_name = file_name
        self.load_data()

    def __len__(self):
        return len(self._quiz)

    def get_all_questions(self):
        return self._quiz

    def save_data(self):
        """saves all the question in the file"""
        f = open(self._file_name, "wt")
        question = self.get_all_questions()
        for sentence in question:
            f.write(sentence.strip()+'\n')
        f.close()

    def load_data(self):
        """gets all the sentences from the file"""
        f = open(self._file_name, "rt")
        for line in f.readlines():
            if line != '\n':
                self._quiz.append(line)
        f.close()

    def add_question(self, id,text,choica,choicb,choicc,corr,diff):
        """adds a sentence to the file and repo"""
        question = str(str(id)+";"+text+";"+choica+";"+choicb+";"+choicc+";"+corr+";"+diff)
        self._quiz.append(question)
        self.save_data()

    def get_question(self, i):
        """gets a sentence from the index i"""
        return self._quiz[i]

