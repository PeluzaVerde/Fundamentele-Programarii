from repo import Repository
from service import service
from ui import UI
import unittest

class allTests(unittest.TestCase):

    def setUp(self) -> None:

        self._repo = Repository("tests.txt")
        self._repo2 = Repository("test1.txt")
        self._service= service(self._repo)
    def test_services(self):
        self._service.add_question(100,"carei 3","4","3","6","3","medium")
        self.assertEqual(self._repo.get_question(1),"100;carei 3;4;3;6;3;medium"+'\n')
        self._service.add_question(102, "carei 3", "4", "3", "6", "3", "medium")
        self._service.add_question(103, "carei 3", "4", "3", "6", "3", "easy")
        self._service.add_question(104, "carei 3", "4", "3", "6", "3", "hard")
        self._service.create_quiz("medium",2,"test1.txt")
        self.assertEqual(len(self._repo2.get_all_questions()),2)